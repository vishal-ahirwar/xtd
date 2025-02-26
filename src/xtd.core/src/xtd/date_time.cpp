#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/date_time.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "../include/xtd/argument_out_of_range_exception.h"
#include "../include/xtd/format_exception.h"
#include "../include/xtd/invalid_operation_exception.h"
#include "../include/xtd/date_time.h"
#include "../include/xtd/math.h"
#include "../include/xtd/not_implemented_exception.h"
#include "../include/xtd/time_zone_info.h"
#include "../include/xtd/unused.h"

using namespace std;
using namespace std::chrono;
using namespace xtd;

namespace {
  // Number of ticks per time unit
  const int64_t ticks_per_millisecond = 10000;
  const int64_t ticks_per_second = ticks_per_millisecond * 1000;
  const int64_t ticks_per_minute = ticks_per_second * 60;
  const int64_t ticks_per_hour = ticks_per_minute * 60;
  const int64_t ticks_per_day = ticks_per_hour * 24;
  
  // Number of seconds per time unit
  const int64_t seconds_per_minute = 60;
  const int64_t seconds_per_our = seconds_per_minute * 60;
  const int64_t seconds_per_day = seconds_per_our * 24;
  
  // Number of days in a non-leap year
  const int64_t days_per_year = 365;
  // Number of days in 4 years
  const int64_t days_per_4_years = days_per_year * 4 + 1; // 1461
  // Number of days in 100 years
  const int64_t days_per_100_years = days_per_4_years * 25 - 1; // 36524
  // Number of days in 400 years
  const int64_t days_per_400_years = days_per_100_years * 4 + 1; // 146097
  
  // Number of days from 1/1/0001 to 12/31/1600
  const int64_t days_to_1601 = days_per_400_years * 4; // 584388
  // Number of days from 1/1/0001 to 12/31/1969
  const int64_t days_to_1970 = days_per_400_years * 4 + days_per_100_years * 3 + days_per_4_years * 17 + days_per_year; // 719,162
  // Number of days from 1/1/0001 to 12/31/9999
  const int64_t days_to_10000 = days_per_400_years * 25 - 366; // 3652059
  
  const ticks min_ticks = ticks(0);
  const ticks max_ticks = ticks(days_to_10000 * ticks_per_day - 1);
  
  const ticks file_time_offset = ticks(days_to_1601* ticks_per_day);
  
  constexpr seconds seconds_offset_1970 = seconds(seconds_per_day* days_to_1970);
  
  static uint32_t get_years(int64_t& days) {
    int64_t year = 1;
    
    if (days >= days_per_400_years) {
      int64_t chunks = days / days_per_400_years;
      year += chunks * 400;
      days -= chunks * days_per_400_years;
    }
    
    if (days >= days_per_100_years) {
      int64_t chunks = days / days_per_100_years;
      if (chunks == 4) chunks = 3;
      year += chunks * 100;
      days -= chunks * days_per_100_years;
    }
    
    if (days >= days_per_4_years) {
      int64_t chunks = days / days_per_4_years;
      year += chunks * 4;
      days -= chunks * days_per_4_years;
    }
    
    if (days >= days_per_year) {
      int64_t chunks = days / days_per_year;
      if (chunks == 4) chunks = 3;
      year += chunks;
      days -= chunks * days_per_year;
    }
    
    return static_cast<uint32_t>(year);
  }
  
  static uint32_t get_months(int64_t& days, uint32_t year) {
    uint32_t month = 1;
    
    for (int64_t days_in_month = date_time::days_in_month(year, month); days >= days_in_month; days_in_month = date_time::days_in_month(year, month)) {
      ++month;
      days -= days_in_month;
    }
    
    return month;
  }
}

const date_time date_time::max_value {max_ticks};
const date_time date_time::min_value {min_ticks};

date_time::date_time(xtd::ticks ticks) : value_(ticks) {
  if (ticks.count() < min_value.value_.count() || ticks.count() > max_value.value_.count()) throw argument_out_of_range_exception(csf_);
}

date_time::date_time(xtd::ticks ticks, xtd::date_time_kind kind) : value_(ticks), kind_(kind) {
  if (ticks.count() < min_value.value_.count() || ticks.count() > max_value.value_.count()) throw argument_out_of_range_exception(csf_);
}

date_time::date_time(uint32_t year, uint32_t month, uint32_t day) {
  set_date_time(year, month, day, 0, 0, 0, 0, date_time_kind::unspecified);
}

date_time::date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second) {
  set_date_time(year, month, day, hour, minute, second, 0, date_time_kind::unspecified);
}

date_time::date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second, date_time_kind kind) {
  set_date_time(year, month, day, hour, minute, second, 0, kind);
}

date_time::date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second, uint32_t millisecond) {
  set_date_time(year, month, day, hour, minute, second, millisecond, date_time_kind::unspecified);
}

date_time::date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second, uint32_t millisecond, date_time_kind kind) {
  set_date_time(year, month, day, hour, minute, second, millisecond, kind);
}

date_time date_time::date() const noexcept {
  uint32_t year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32_t day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return date_time(year, month, day, 0, 0, 0, 0, kind_);
}

uint32_t date_time::day() const noexcept {
  uint32_t year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32_t day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return day;
}

xtd::day_of_week date_time::day_of_week() const noexcept {
  uint32_t year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32_t day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return static_cast<xtd::day_of_week>(day_of_week);
}

uint32_t date_time::day_of_year() const noexcept {
  uint32_t year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32_t day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return day_of_year;
}

uint32_t date_time::hour() const noexcept {
  uint32_t year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32_t day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return hour;
}

date_time_kind date_time::kind() const noexcept {
  return kind_;
}

uint32_t date_time::millisecond() const noexcept {
  return duration_cast<chrono::milliseconds>(value_).count() % 1000;
}

uint32_t date_time::minute() const noexcept {
  uint32_t year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32_t day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return minute;
}

uint32_t date_time::month() const noexcept {
  uint32_t year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32_t day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return month;
}

date_time date_time::now() noexcept {
  system_clock::time_point now = system_clock::now();
  auto now_ticks = duration_cast<xtd::ticks>(now.time_since_epoch()) % ticks_per_second;
  return from_time_t(system_clock::to_time_t(now), date_time_kind::local).add(now_ticks);
}

uint32_t date_time::second() const noexcept {
  uint32_t year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32_t day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return second;
}

xtd::ticks date_time::ticks() const noexcept {
  return value_;
}

date_time::time_point date_time::time_of_day() const noexcept {
  uint32_t year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32_t day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return duration_cast<time_point>(chrono::hours(hour)) + duration_cast<time_point>(chrono::minutes(minute)) + duration_cast<time_point>(chrono::seconds(second));
}

date_time date_time::today() noexcept {
  date_time today = now();
  uint32_t year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32_t day_of_week = 0;
  today.get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return date_time(year, month, day, 0, 0, 0, 0, today.kind_);
}

date_time date_time::utc_now() noexcept {
  return now().to_universal_time();
}

uint32_t date_time::year() const noexcept {
  uint32_t year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32_t day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  return year;
}

date_time date_time::add(time_point value) const {
  return date_time(value_ + value, kind_);
}

date_time date_time::add_days(double days) const {
  return date_time(value_ + xtd::ticks(static_cast<int64_t>(days * ticks_per_day)), kind_);
}

date_time date_time::add_hours(double hours) const {
  return date_time(value_ + xtd::ticks(static_cast<int64_t>(hours * ticks_per_hour)), kind_);
}

date_time date_time::add_milliseconds(double milliseconds) const {
  return date_time(value_ + xtd::ticks(static_cast<int64_t>(milliseconds * ticks_per_millisecond)), kind_);
}

date_time date_time::add_minutes(double minute) const {
  return date_time(value_ + xtd::ticks(static_cast<int64_t>(minute * ticks_per_minute)), kind_);
}

date_time date_time::add_months(int32_t months) const {
  if (months < -120000 || months > 120000) throw argument_out_of_range_exception(csf_);
  
  uint32_t year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32_t day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  
  int32_t i = month - 1 + months;
  if (i >= 0) {
    month = static_cast<uint32_t>(i % 12 + 1);
    year = year + static_cast<uint32_t>(i / 12);
  } else {
    month = static_cast<uint32_t>(12 + (i + 1) % 12);
    year = year + static_cast<uint32_t>((i - 11) / 12);
  }
  if (year < 1U || year > 9999U) throw argument_out_of_range_exception(csf_);
  uint32_t days = static_cast<uint32_t>(days_in_month(year, month));
  if (day > days) day = days;
  return date_time(year, month, day, hour, minute, second, kind_);
}

date_time date_time::add_seconds(double value) const {
  return date_time(value_ + xtd::ticks(static_cast<int64_t>(value * ticks_per_second)), kind_);
}

date_time date_time::add_ticks(int64 value) const {
  return date_time(value_ + xtd::ticks(value), kind_);
}

date_time date_time::add_years(int32_t value) const {
  return add_months(value * 12);
}

int32_t date_time::compare_to(const object& obj) const noexcept {
  if (!dynamic_cast<const date_time*>(&obj)) return 1;
  return compare_to(static_cast<const date_time&>(obj));
}

int32_t date_time::compare_to(const date_time& value) const noexcept {
  if (value_.count() < value.value_.count()) return -1;
  if (value_.count() > value.value_.count()) return 1;
  return 0;
}

int32_t date_time::days_in_month(uint32_t year, month_of_year month) {
  return days_in_month(year, static_cast<uint32_t>(month));
}

int32_t date_time::days_in_month(uint32_t year, uint32_t month) {
  if (month < 1 || month > 12) throw argument_out_of_range_exception(csf_);
  if (month == 2) return is_leap_year(year) ? 29 : 28;
  if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
  return 31;
}

bool date_time::equals(const date_time& other) const noexcept {
  return value_.count() == other.value_.count();
}

bool date_time::equals(const object& other) const noexcept {
  return dynamic_cast<const date_time*>(&other) && equals(static_cast<const date_time&>(other));
}

date_time date_time::from_binary(int64_t date_data) {
  return date_time(xtd::ticks(date_data & 0x3FFFFFFFFFFFFFFFLL), static_cast<date_time_kind>(static_cast<int32_t>(((date_data & 0xC000000000000000LL) >> 62) & 0x0000000000000003LL)));
}

date_time date_time::from_file_time(int64_t file_time) {
  return from_file_time_utc(file_time).to_local_time();
}

date_time date_time::from_file_time_utc(int64_t file_time) {
  if (file_time < 0) throw argument_out_of_range_exception(csf_);
  return date_time(xtd::ticks(file_time) + file_time_offset, date_time_kind::utc);
}

date_time date_time::from_time_t(std::time_t value) {
  return from_time_t(value, date_time_kind::unspecified);
}

date_time date_time::from_time_t(std::time_t value, date_time_kind kind) {
  return date_time::specify_kind(date_time(duration_cast<xtd::ticks>(chrono::seconds(value) + seconds_offset_1970), date_time_kind::utc), kind);
}

date_time date_time::from_tm(const tm& value) {
  return from_tm(value, date_time_kind::unspecified);
}

date_time date_time::from_tm(const tm& value, date_time_kind kind) {
  return date_time(value.tm_year + 1900, value.tm_mon + 1, value.tm_mday, value.tm_hour, value.tm_min, value.tm_sec, kind);
}

bool date_time::is_daylight_saving_time() const noexcept {
  if (kind_ != date_time_kind::local) return false;
  return native::date_time::is_daylight((duration_cast<chrono::seconds>(value_) - seconds_offset_1970).count());
}

bool date_time::is_leap_year(uint32_t year) {
  if (year < 1 || year > 9999) throw argument_out_of_range_exception(csf_);
  return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

date_time date_time::parse(const xtd::ustring& s) {
  throw not_implemented_exception(csf_);
}

date_time date_time::specify_kind(date_time value, date_time_kind kind) {
  if (kind == date_time_kind::local && value.kind_ != date_time_kind::local) return value.to_local_time();
  if (kind == date_time_kind::utc && value.kind_ != date_time_kind::utc) return value.to_universal_time();
  if (kind == date_time_kind::unspecified) return date_time(value.value_, date_time_kind::unspecified);
  return value;
}

ustring date_time::sprintf(const ustring& format) const {
  std::stringstream result;
  result.imbue(locale());
  tm tm_value = to_tm();
  result << std::put_time(&tm_value, format.c_str());
  return result.str();
}

date_time::time_point date_time::subtract(const date_time& value) const {
  return time_point(duration_cast<time_point>(value_ - value.value_));
}

date_time date_time::subtract(time_point value) const {
  return date_time(value_ - duration_cast<xtd::ticks>(value));
}

int64_t date_time::to_binary() const {
  return (duration_cast<chrono::seconds>(value_).count() & 0x3FFFFFFFFFFFFFFFLL) + ((static_cast<int64>(kind_) << 62) & 0xC000000000000000LL);
}

int64_t date_time::to_file_time() const {
  return to_universal_time().to_file_time_utc();
}

int64_t date_time::to_file_time_utc() const {
  auto value = kind_ == date_time_kind::unspecified ? to_universal_time().value_ : value_;
  int64_t result = (value - file_time_offset).count();
  if (result < 0) throw argument_out_of_range_exception(csf_);
  return result;
}

date_time date_time::to_local_time() const {
  if (kind_ == date_time_kind::local) return *this;
  
  auto utc_offset = this->utc_offset();
  if (value_ + utc_offset > max_value.value_) return date_time(value_, date_time_kind::local);
  
  uint32_t year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32_t day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year, day_of_week);
  
  return date_time(ticks() + utc_offset, date_time_kind::local);
}

const xtd::ustring date_time::to_long_date_string() const {
  return to_string("n");
}

const xtd::ustring date_time::to_long_time_string() const {
  return to_string("T");
}

const xtd::ustring date_time::to_short_date_string() const {
  return to_string("D");
}

const xtd::ustring date_time::to_short_time_string() const {
  return to_string("V");
}

xtd::ustring date_time::to_string() const noexcept {
  return to_string("G");
}

ustring date_time::to_string(const ustring& format) const {
  auto fmt = format;
  if (fmt.empty()) fmt =  "G";
  if (fmt.size() > 1) format_exception("Invalid format", csf_);
  
  uint32_t year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32_t day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year,  day_of_week);
  
  switch (fmt[0]) {
    case 'a': return ustring::format("{}", hour / 12 ? "PM" : "AM");
    case 'b': return ustring::format("{:D3}", millisecond());
    case 'B': return ustring::format("{}", millisecond());
    case 'c': return ustring::format("{:D7}", ticks().count() % ticks_per_millisecond);
    case 'C': return ustring::format("{}", ticks().count() % ticks_per_millisecond);
    case 'd': return ustring::format("{:D2}/{:D2}/{:D}", month, day, year);
    case 'D': return ustring::format("{:D}/{:D2}/{:D}", month, day, year);
    case 'e': return ustring::format("{:D2}", second);
    case 'E': return ustring::format("{}", second);
    case 'f': return sprintf("%Ec");
    case 'F': return sprintf("%c");
    case 'g': return sprintf("%Ec");
    case 'G': return sprintf("%c");
    case 'h': return sprintf("%a");
    case 'H': return sprintf("%A");
    case 'i': return ustring::format("{:D2}", day);
    case 'I': return ustring::format("{:D}", day);
    case 'j': return sprintf("%b");
    case 'J': return sprintf("%B");
    case 'k': return ustring::format("{:D2}", month);
    case 'K': return ustring::format("{:D}", month);
    case 'l': return ustring::format("{:D2}", year % 100);
    case 'L': return ustring::format("{:D4}", year);
    case 'm': return ustring::format("{:D}", year);
    case 'M': return ustring::format("{} {:D}", sprintf("%B"), day);
    case 'n': return ustring::format("{}, {:D} {} {:D}", sprintf("%A"), day, sprintf("%B"), year);
    case 'N': return ustring::format("{}, {:D} {} {:D} {:D}:{:D2}:{:D2}", sprintf("%A"), day, sprintf("%B"), year, hour, minute, second);
    case 'o':
    case 'O': return ustring::format("{:D} {} {:D}", day, sprintf("%B"), year);
    case 'p': return ustring::format("{:D2}", minute);
    case 'P': return ustring::format("{}", minute);
    case 's': return ustring::format("{:D4}-{:D2}-{:D2}T{:D2}:{:D2}:{:D2}.{:D7}", year, month, day, hour, minute, second, value_.count() % ticks_per_second);
    case 't': return ustring::format("{:D2}:{:D2}:{:D2}", hour, minute, second);
    case 'T': return ustring::format("{:D}:{:D2}:{:D2}", hour, minute, second);
    case 'u': return ustring::format("{:D}-{:D2}-{:D2} {:D2}:{:D2}:{:D2}", year, month, day, hour, minute, second);
    case 'U': return ustring::format("{}, {:D} {} {:D} {:D}:{:D2}:{:D2}", sprintf("%A"), day, sprintf("%B"), year, hour, minute, second);
    case 'v': return ustring::format("{:D2}:{:D2}", hour, minute);
    case 'V': return ustring::format("{:D}:{:D2}", hour, minute);
    case 'w': return ustring::format("{:D2}", hour);
    case 'W': return ustring::format("{:D}", hour);
    case 'x': return ustring::format("{:D2}", hour % 12);
    case 'X': return ustring::format("{:D}", hour % 12);
    case 'y': return ustring::format("{} {:D}", sprintf("%B"), year % 100);
    case 'Y': return ustring::format("{} {:D}", sprintf("%B"), year);
    case 'z':
    case 'Z': return kind_ == date_time_kind::local ? time_zone_info::local().id().c_str() : time_zone_info::utc().id().c_str();
  }
  throw format_exception("Invalid format");
}

std::time_t date_time::to_time_t() const {
  return (duration_cast<chrono::seconds>(date_time::specify_kind(*this, date_time_kind::utc).value_) - seconds_offset_1970).count();
}

std::tm date_time::to_tm() const {
  uint32_t year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32_t day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year, day_of_week);
  
  std::tm result {};
  result.tm_sec = static_cast<int32_t>(second);
  result.tm_min = static_cast<int32_t>(minute);
  result.tm_hour = static_cast<int32_t>(hour);
  result.tm_mday = static_cast<int32_t>(day);
  result.tm_mon = static_cast<int32_t>(month - 1);
  result.tm_year = static_cast<int32_t>(year - 1900);
  result.tm_wday = day_of_week;
  result.tm_yday = static_cast<int32_t>(day_of_year);
  result.tm_isdst = is_daylight_saving_time();
  return result;
}

date_time::operator date_time::time_point() const {
  return time_point(value_);
}

date_time date_time::to_universal_time() const {
  if (kind_ == date_time_kind::utc) return *this;
  
  auto utc_offset = this->utc_offset();
  if (value_ < utc_offset) return date_time(value_, date_time_kind::utc);
  
  uint32_t year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, day_of_year = 0;
  int32_t day_of_week = 0;
  get_date_time(year, month, day, hour, minute, second, day_of_year, day_of_week);
  
  return date_time(ticks() - utc_offset, date_time_kind::utc);
}

date_time& date_time::operator+=(const date_time& value) {
  value_ += value.value_;
  return *this;
}

date_time& date_time::operator-=(const date_time& value) {
  value_ -= value.value_;
  return *this;
}

date_time date_time::operator+() {
  return date_time(+value_, kind_);
}

date_time date_time::operator-() {
  return date_time(-value_, kind_);
}

date_time date_time::operator+(const date_time& value) const {
  date_time result = *this;
  result.value_ += value.value_;
  return result;
}

date_time date_time::operator-(const date_time& value) const {
  date_time result = *this;
  result.value_ -= value.value_;
  return result;
}

date_time& date_time::operator++() {
  ++value_;
  return *this;
}

date_time date_time::operator++(int) {
  return date_time(value_++, kind_);
}

date_time& date_time::operator--() {
  --value_;
  return *this;
}

date_time date_time::operator--(int) {
  return date_time(value_--, kind_);
}

void date_time::get_date_time(uint32_t& year, uint32_t& month, uint32_t& day, uint32_t& hour, uint32_t& minute, uint32_t& second, uint32_t& day_of_year, int32_t& day_of_week) const {
  int64_t days = value_.count() / ticks_per_day;
  year = get_years(days);
  day_of_year = static_cast<uint32_t>(days + 1);
  month = get_months(days, year);
  day = static_cast<uint32_t>(days + 1);
  hour = static_cast<uint32_t>(value_.count() / ticks_per_hour % 24);
  minute = static_cast<uint32_t>(value_.count() / ticks_per_minute % 60);
  second = static_cast<uint32_t>(value_.count() / ticks_per_second % 60);
  day_of_week = (static_cast<int32_t>(value_.count() / ticks_per_day + 1) % 7);
}

xtd::ticks date_time::utc_offset() const {
  return duration_cast<xtd::ticks>(std::chrono::seconds(native::date_time::utc_offset((duration_cast<chrono::seconds>(value_) - seconds_offset_1970).count())));
}

void date_time::set_date_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second, uint32_t millisecond, date_time_kind kind) {
  uint32_t day_of_year = 0;
  int32_t day_of_week = 0;
  
  uint32_t max_year = 1, max_month = 1, max_day = 1, max_hour = 0, max_minute = 0, max_second = 0;
  max_value.get_date_time(max_year, max_month, max_day, max_hour, max_minute, max_second, day_of_year, day_of_week);
  
  uint32_t min_year = 1, min_month = 1, min_day = 1, min_hour = 0, min_minute = 0, min_second = 0;
  min_value.get_date_time(min_year, min_month, min_day, min_hour, min_minute, min_second, day_of_year, day_of_week);
  
  if (year  < min_year ||
    (year == min_year && month  < min_month) ||
    (year == min_year && month == min_month && day  < min_day) ||
    (year == min_year && month == min_month && day == min_day && hour  < min_hour) ||
    (year == min_year && month == min_month && day == min_day && hour == min_hour && minute  < min_minute) ||
    (year == min_year && month == min_month && day == min_day && hour == min_hour && minute == min_minute && second < min_second))
    throw argument_out_of_range_exception(csf_);
    
  if (year  > max_year ||
    (year == max_year && month  > max_month) ||
    (year == max_year && month == max_month && day  > max_day) ||
    (year == max_year && month == max_month && day == max_day && hour > max_hour) ||
    (year == max_year && month == max_month && day == max_day && hour == max_hour && minute > max_minute) ||
    (year == max_year && month == max_month && day == max_day && hour == max_hour && minute == max_minute && second > max_second))
    throw argument_out_of_range_exception(csf_);
    
  int64_t days = day - 1;
  
  for (uint32_t index = 1; index < month; ++index)
    days += days_in_month(year, index);
    
  --year;
  days += (year * days_per_year) + (year / 4) - (year / 100) + (year / 400);
  value_ = xtd::ticks(days * ticks_per_day + hour * ticks_per_hour + minute * ticks_per_minute + second * ticks_per_second + millisecond * ticks_per_millisecond);
  kind_ = kind;
}

std::ostream& xtd::operator<<(std::ostream& os, const date_time& value) noexcept {
  return os << value.to_string();
}
