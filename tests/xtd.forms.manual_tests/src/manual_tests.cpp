#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form_test : public form {
public:
  form_test() {
    this->text("xtd.forms.manual_tests");

    this->progress_bar1.location({100, 50});
    this->progress_bar1.maximum(200);
    this->progress_bar1.orientation(forms::orientation::vertical);
    this->progress_bar1.parent(*this);
    this->progress_bar1.size({23, 200});
    
    this->label1.location({150, 50});
    this->label1.parent(*this);

    this->track_bar1.location({50, 50});
    this->track_bar1.maximum(200);
    this->track_bar1.orientation(forms::orientation::vertical);
    this->track_bar1.parent(*this);
    this->track_bar1.value_changed += [&] {
      this->progress_bar1.value(this->track_bar1.value());
      this->label1.text(strings::format("{}", this->track_bar1.value()));
    };
    this->track_bar1.value(100);
    this->track_bar1.tick_style(forms::tick_style::bottom_right);
    this->track_bar1.size({45, 200});
  }
  
private:
  track_bar track_bar1;
  progress_bar progress_bar1;
  label label1;
};

int main() {
  application::run(form_test());
}
