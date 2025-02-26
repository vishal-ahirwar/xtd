#include <chrono>
#include <memory>
#include <thread>
#include <vector>
#include <xtd/literals.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/about_dialog.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/diagnostics/process.h>
#include <xtd/drawing/system_icons.h>
#include "../../../include/xtd/forms/about_dialog.h"
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/form.h"
#include "../../../include/xtd/forms/horizontal_layout_panel.h"
#include "../../../include/xtd/forms/label.h"
#include "../../../include/xtd/forms/link_label.h"
#include "../../../include/xtd/forms/panel.h"
#include "../../../include/xtd/forms/picture_box.h"
#include "../../../include/xtd/forms/tab_control.h"
#include "../../../include/xtd/forms/tab_page.h"
#include "../../../include/xtd/forms/text_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace {
  class credits_item_panel : public horizontal_layout_panel {
  public:
    credits_item_panel() {
      padding(forms::padding {5});
      controls().push_back_range({title_label_, names_label_});
      title_label_.text_align(content_alignment::top_right);
      title_label_.font({title_label_.font(), font_style::bold});
      names_label_.text_align(content_alignment::top_left);
      names_label_.auto_size(true);
      auto_size(true);
    }
    
    const string title() const {return title_;}
    credits_item_panel& title(const xtd::ustring& title) {
      if (title_ != title) {
        title_ = title;
        title_label_.text(title);
      }
      return *this;
    }
    
    const vector<ustring>& names() const {return names_;}
    credits_item_panel& names(const vector<ustring>& names) {
      if (names_ != names) {
        bool first = true;
        names_ = names;
        names_label_.text("");
        for (auto name : names_) {
          names_label_.text(ustring::format("{}{}{}", names_label_.text(), first ? "" : "\n", name));
          first = false;
        }
      }
      return *this;
    }
    
  protected:
    void on_create_control() override {
      horizontal_layout_panel::on_create_control();
      control_layout_style(title_label_, {.50f, size_type::percent});
      control_layout_style(names_label_, {.50f, size_type::percent});
    }
    
  private:
    label title_label_;
    label names_label_;
    vector<ustring> names_;
    string title_;
  };
  
  class about_dialog_standard : public form {
  public:
    about_dialog_standard() {
      maximize_box(false);
      minimize_box(false);
      show_icon(false);
      show_in_taskbar(false);
      client_size({476, 300});
      form_border_style(forms::form_border_style::fixed_dialog);
      start_position(form_start_position::center_screen);
      
      picture_box_icon_.height(74);
      picture_box_icon_.size_mode(picture_box_size_mode::center_image);
      picture_box_icon_.padding(5);
      picture_box_icon_.dock(dock_style::top);
      
      label_name_.text_align(content_alignment::middle_center);
      label_name_.font({label_name_.font(), label_name_.font().size() + 4, xtd::drawing::font_style::bold});
      label_name_.padding(5);
      label_name_.dock(dock_style::top);
      
      tab_page_about_.text("About"_t);
      
      tab_page_credits_.text("Credits"_t);
      tab_page_credits_.auto_scroll(true);
      
      tab_page_license_.text("License"_t);
      tab_page_license_.controls().push_back(text_box_license_);
      
      tab_control_about_.padding(5);
      tab_control_about_.dock(dock_style::fill);
      
      panel_about_.padding(5);
      panel_about_.controls().push_back_range({label_copyright_, link_label_website_, label_description_, label_version_});
      panel_about_.dock(dock_style::fill);
      
      label_version_.text_align(content_alignment::middle_center);
      label_version_.padding(5);
      label_version_.dock(dock_style::top);
      
      label_description_.text_align(content_alignment::middle_center);
      label_description_.font({label_description_.font(), label_description_.font().size() + 2, xtd::drawing::font_style::bold});
      label_description_.padding(5);
      label_description_.dock(dock_style::top);
      
      link_label_website_.text_align(content_alignment::middle_center);
      link_label_website_.padding(5);
      link_label_website_.dock(dock_style::top);
      
      label_copyright_.text_align(content_alignment::middle_center);
      label_copyright_.padding(5);
      label_copyright_.dock(dock_style::top);
      
      text_box_license_.multiline(true);
      text_box_license_.read_only(true);
      text_box_license_.word_wrap(false);
      text_box_license_.dock(dock_style::fill);
    }
    
    static void show(intptr_t hwnd, const xtd::drawing::image& icon, const xtd::ustring& name, const xtd::ustring& description, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label, const std::vector<ustring>& authors, const std::vector<ustring>& artists, const std::vector<ustring>& documenters, const std::vector<ustring>& translators, const xtd::ustring& license) {
      if (about_dialog != nullptr) {
        about_dialog->activate();
        return;
      }
      about_dialog = new about_dialog_standard();
      auto has_credit = !(authors.empty() && documenters.empty() && translators.empty() && artists.empty());
      auto has_license = !license.empty();
      if (icon != xtd::drawing::bitmap::empty)
        about_dialog->picture_box_icon_.image(xtd::drawing::bitmap(icon, {64, 64}));
      else
        about_dialog->picture_box_icon_.image(xtd::drawing::system_images::from_name("xtd-forms", xtd::drawing::size(64, 64)));
      about_dialog->label_name_.height(static_cast<int32_t>(30 * name.split({'\n'}).size()));
      about_dialog->label_name_.text(name);
      if (has_credit || has_license) {
        about_dialog->controls().push_back_range({about_dialog->tab_control_about_, about_dialog->label_name_, about_dialog->picture_box_icon_});
        about_dialog->tab_control_about_.tab_pages().push_back(about_dialog->tab_page_about_);
        about_dialog->tab_page_about_.controls().push_back(about_dialog->panel_about_);
      } else {
        about_dialog->maximum_size({0, 0});
        about_dialog->minimum_size({0, 0});
        about_dialog->client_size({476, 250});
        about_dialog->maximum_size(about_dialog->size());
        about_dialog->minimum_size(about_dialog->size());
        about_dialog->controls().push_back_range({about_dialog->panel_about_, about_dialog->label_name_, about_dialog->picture_box_icon_});
      }
      
      if (!version.empty() && !long_version.empty())
        about_dialog->label_version_.text(xtd::ustring::format("{} ({})", long_version, version));
      else if (!long_version.empty())
        about_dialog->label_version_.text(xtd::ustring::format("{}", long_version));
      else if (!version.empty())
        about_dialog->label_version_.text(xtd::ustring::format("({})", version));
        
      about_dialog->label_description_.height(static_cast<int32_t>(23 * description.split({'\n'}).size()));
      about_dialog->label_description_.text(xtd::ustring::format("{}", description));
      
      about_dialog->link_label_website_.height(static_cast<int32_t>(23 * (!website_label.empty() ? website_label : website).split({'\n'}).size()));
      about_dialog->link_label_website_.text(!website_label.empty() ? website_label : website);
      about_dialog->link_label_website_.link_clicked += [&](object & sender, link_label_clicked_event_args & e) {
        e.visited(true);
        diagnostics::process::start(website);
      };
      
      about_dialog->label_copyright_.height(static_cast<int32_t>(23 * copyright.split({'\n'}).size()));
      about_dialog->label_copyright_.text(xtd::ustring::format("{}", ustring(copyright).replace(u8"(c)"_s, u8"\u00A9"_s)));
      
      if (has_credit) {
        about_dialog->tab_control_about_.tab_pages().push_back(about_dialog->tab_page_credits_);
        about_dialog->tab_page_credits_.auto_scroll(true);
        
        if (!artists.empty()) {
          about_dialog->artists_.parent(about_dialog->tab_page_credits_);
          about_dialog->artists_.dock(dock_style::top);
          about_dialog->artists_.title("Artwork by");
          about_dialog->artists_.names(artists);
        }
        
        if (!translators.empty()) {
          about_dialog->translators_.parent(about_dialog->tab_page_credits_);
          about_dialog->translators_.dock(dock_style::top);
          about_dialog->translators_.title("Translated by");
          about_dialog->translators_.names(translators);
        }
        
        if (!documenters.empty()) {
          about_dialog->documenters_.parent(about_dialog->tab_page_credits_);
          about_dialog->documenters_.dock(dock_style::top);
          about_dialog->documenters_.title("Documented by");
          about_dialog->documenters_.names(documenters);
        }
        
        if (!authors.empty()) {
          about_dialog->authors_.parent(about_dialog->tab_page_credits_);
          about_dialog->authors_.dock(dock_style::top);
          about_dialog->authors_.title("Created by");
          about_dialog->authors_.names(authors);
        }
      }
      
      if (has_license) {
        about_dialog->tab_control_about_.tab_pages().push_back(about_dialog->tab_page_license_);
        about_dialog->text_box_license_.text(license);
      }
      
      about_dialog->visible(true);
    }
    
  private:
    void on_form_closed(const form_closed_event_args& e) override {
      form::on_form_closed(e);
      delete about_dialog;
      about_dialog = nullptr;
    }
    inline static about_dialog_standard* about_dialog = nullptr;
    picture_box picture_box_icon_;
    label label_name_;
    tab_control tab_control_about_;
    tab_page tab_page_about_;
    panel panel_about_;
    label label_version_;
    label label_description_;
    label label_copyright_;
    link_label link_label_website_;
    tab_page tab_page_credits_;
    credits_item_panel authors_;
    credits_item_panel documenters_;
    credits_item_panel translators_;
    credits_item_panel artists_;
    tab_page tab_page_license_;
    text_box text_box_license_;
  };
}

void about_dialog::reset() {
  data_->dialog_style = xtd::forms::dialog_style::standard;
  data_->icon = xtd::drawing::image::empty;
  data_->artists.clear();
  data_->authors.clear();
  data_->copyright = "";
  data_->description = "";
  data_->documenters.clear();
  data_->license = "";
  data_->long_version = "";
  data_->name = "";
  data_->translators.clear();
  data_->version = "";
  data_->website = "";
  data_->website_label = "";
}

void about_dialog::show() {
  if (data_->dialog_style == xtd::forms::dialog_style::system) native::about_dialog::show(0, xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(data_->icon)), data_->name, data_->description, data_->version, data_->long_version, data_->copyright, data_->website, data_->website_label, data_->authors.to_array(), data_->artists.to_array(), data_->documenters.to_array(), data_->translators.to_array(), data_->license);
  else about_dialog_standard::show(0, data_->icon, data_->name, data_->description, data_->version, data_->long_version, data_->copyright, data_->website, data_->website_label, data_->authors.to_array(), data_->artists.to_array(), data_->documenters.to_array(), data_->translators.to_array(), data_->license);
}

void about_dialog::show(const iwin32_window& owner) {
  if (data_->dialog_style == xtd::forms::dialog_style::system) native::about_dialog::show(owner.handle(), xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(data_->icon)), data_->name, data_->description, data_->version, data_->long_version, data_->copyright, data_->website, data_->website_label, data_->authors.to_array(), data_->artists.to_array(), data_->documenters.to_array(), data_->translators.to_array(), data_->license);
  else about_dialog_standard::show(owner.handle(), data_->icon, data_->name, data_->description, data_->version, data_->long_version, data_->copyright, data_->website, data_->website_label, data_->authors.to_array(), data_->artists.to_array(), data_->documenters.to_array(), data_->translators.to_array(), data_->license);
}
