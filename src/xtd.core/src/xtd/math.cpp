#include "../../include/xtd/math.h"
#include "../../include/xtd/as.h"
#include "../../include/xtd/overflow_exception.h"
#include <cmath>
#include <cstdlib>
#include <limits>

using namespace std;
using namespace xtd;

namespace {
}

decimal_t math::abs(decimal_t value) {
  return value < 0 ? -value : value;
}

double math::abs(double value) {
  return value < 0 ? -value : value;
}

float math::abs(float value) {
  return value < 0 ? -value : value;
}

int16_t math::abs(int16_t value) {
  if (value == numeric_limits<int16_t>::lowest()) throw xtd::overflow_exception(csf_);
  return value < 0 ? -value : value;
}

int32_t math::abs(int32_t value) {
  if (value == numeric_limits<int32_t>::lowest()) throw xtd::overflow_exception(csf_);
  return value < 0 ? -value : value;
}

int64_t math::abs(int64_t value) {
  if (value == numeric_limits<int64_t>::lowest()) throw xtd::overflow_exception(csf_);
  return value < 0 ? -value : value;
}

sbyte_t math::abs(sbyte_t value) {
  if (value == numeric_limits<sbyte_t>::lowest()) throw xtd::overflow_exception(csf_);
  return value < 0 ? -value : value;
}

llong_t math::abs(llong_t value) {
  if (value == numeric_limits<llong_t>::lowest()) throw xtd::overflow_exception(csf_);
  return value < 0 ? -value : value;
}

double math::acos(double value) {
  return std::acos(value);
}

double math::asin(double value) {
  return std::asin(value);
}

double math::atan(double value) {
  return std::atan(value);
}

double math::atan2(double y, double x) {
  return is_infinity(y) && is_infinity(x) ? NaN : std::atan2(y, x);
}

int64_t math::big_mul(int32_t a, int32_t b) {
  return as<int64_t>(a) * as<int64_t>(b);
}

decimal math::ceiling(decimal value) {
  return std::ceil(value);
}

double math::ceiling(double value) {
  return std::ceil(value);
}

double math::cos(double value) {
  return std::cos(value);
}

double math::cosh(double value) {
  return std::cosh(value);
}

double math::degrees_to_radians(double degrees) {
  return degrees * (math::pi / 180);
}

int32_t math::div_rem(int32_t dividend, int32_t divisor, int32_t& remainder) {
  remainder = dividend % divisor;
  return dividend / divisor;
}

int64_t math::div_rem(int64_t dividend, int64_t divisor, int64_t& remainder) {
  remainder = dividend % divisor;
  return dividend / divisor;
}

double math::exp(double value) {
  return std::exp(value);
}

double math::ieee_remainder(double dividend, double divisor) {
  return divisor == 0 ? NaN : dividend - (divisor * math::round(dividend / divisor));
}

decimal_t math::floor(decimal_t value) {
  return std::floor(value);
}

double math::floor(double value) {
  return std::floor(value);
}

bool math::is_infinity(double value) {
  return is_negative_infinity(value) || is_positive_infinity(value);
}

bool math::is_negative_infinity(double value) {
  return value <= negative_infinity;
}

bool math::is_positive_infinity(double value) {
  return value >= positive_infinity;
}

bool math::is_NaN(double value) {
  return value != value;
}

double math::log(double value) {
  return std::log(value);
}

double math::log(double a, double newBase) {
  if (a < 0 || newBase < 0 || (a != 1 && newBase == 0) || (a != 1 && math::is_positive_infinity(newBase)) || math::is_NaN(a) || math::is_NaN(newBase) || newBase == 1) return math::NaN;
  if ((a == 0 && 0 < newBase && newBase < 1) || (math::is_positive_infinity(a) && newBase > 1)) return math::positive_infinity;
  if ((a == 0 && newBase > 1) || (math::is_positive_infinity(a) && 0 < newBase && newBase < 1)) return math::negative_infinity;
  return (math::log(a) / math::log(newBase));
}

double math::log10(double value) {
  return std::log10(value);
}

byte_t math::max(byte_t a, byte_t b) {
  return a > b ? a : b;
}

decimal_t math::max(decimal_t a, decimal_t b) {
  return a > b ? a : b;
}

double math::max(double a, double b) {
  return a > b ? a : b;
}

int16_t math::max(int16_t a, int16_t b) {
  return a > b ? a : b;
}

int32_t math::max(int32_t a, int32_t b) {
  return a > b ? a : b;
}

int64_t math::max(int64_t a, int64_t b) {
  return a > b ? a : b;
}

llong_t math::max(llong_t a, llong_t b) {
  return a > b ? a : b;
}

sbyte_t math::max(sbyte_t a, sbyte_t b) {
  return a > b ? a : b;
}

float math::max(float a, float b) {
  return a > b ? a : b;
}

uint16_t math::max(uint16_t a, uint16_t b) {
  return a > b ? a : b;
}

uint32_t math::max(uint32_t a, uint32_t b) {
  return a > b ? a : b;
}

uint64_t math::max(uint64_t a, uint64_t b) {
  return a > b ? a : b;
}

ullong_t math::max(ullong_t a, ullong_t b) {
  return a > b ? a : b;
}

byte_t math::min(byte_t a, byte_t b) {
  return a < b ? a : b;
}

decimal_t math::min(decimal_t a, decimal_t b) {
  return a < b ? a : b;
}

double math::min(double a, double b) {
  return a < b ? a : b;
}

int16_t math::min(int16_t a, int16_t b) {
  return a < b ? a : b;
}

int32_t math::min(int32_t a, int32_t b) {
  return a < b ? a : b;
}

int64_t math::min(int64_t a, int64_t b) {
  return a < b ? a : b;
}

llong_t math::min(llong_t a, llong_t b) {
  return a < b ? a : b;
}

sbyte_t math::min(sbyte_t a, sbyte_t b) {
  return a < b ? a : b;
}

float math::min(float a, float b) {
  return a < b ? a : b;
}

uint16_t math::min(uint16_t a, uint16_t b) {
  return a < b ? a : b;
}

uint32_t math::min(uint32_t a, uint32_t b) {
  return a < b ? a : b;
}

uint64_t math::min(uint64_t a, uint64_t b) {
  return a < b ? a : b;
}

ullong_t math::min(ullong_t a, ullong_t b) {
  return a < b ? a : b;
}

double math::pow(double x, double y) {
  return std::pow(x, y);
}

double math::radians_to_degrees(double radians) {
  return radians * (180 / math::pi);
}

decimal_t math::round(decimal_t value) {
  return math::round(value, 0);
}

decimal_t math::round(decimal_t value, int32_t decimals) {
  decimal_t muliplicator = 1;
  for (int32_t index = 0; index < decimals; index++)
    muliplicator *= 10;
  return math::floor((value * muliplicator) + 0.5) / muliplicator;
}

double math::round(double value) {
  return math::round(value, 0);
}

double math::round(double value, int32_t decimals) {
  double multiplicator = 1.0;
  for (int32_t index = 0; index < decimals; index++)
    multiplicator *= 10.0;
  return math::floor((value * multiplicator) + 0.5) / multiplicator;
}

int32_t math::sign(decimal_t value) {
  if (value != value) throw arithmetic_exception(csf_);
  return value < 0 ? -1 : value == 0 ? 0 : 1;
}

int32_t math::sign(double value) {
  if (is_NaN(value)) throw arithmetic_exception(csf_);
  return value < 0.0 ? -1 : value == 0.0 ? 0 : 1;
}

int32_t math::sign(int16_t value) {
  return value < 0 ? -1 : value == 0 ? 0 : 1;
}

int32_t math::sign(int32_t value) {
  return value < 0 ? -1 : value == 0 ? 0 : 1;
}

int32_t math::sign(int64_t value) {
  return value < 0 ? -1 : value == 0 ? 0 : 1;
}

int32_t math::sign(sbyte_t value) {
  return value < 0 ? -1 : value == 0 ? 0 : 1;
}

int32_t math::sign(float value) {
  if (value != value) throw arithmetic_exception(csf_);
  return value < 0.0f ? -1 : value == 0.0f ? 0 : 1;
}

double math::sin(double value) {
  return std::sin(value);
}

double math::sinh(double value) {
  return std::sinh(value);
}

double math::sqrt(double value) {
  return std::sqrt(value);
}

double math::tan(double value) {
  return std::tan(value);
}

double math::tanh(double value) {
  return std::tanh(value);
}

decimal math::truncate(decimal value) {
  return (value > 0) ? math::floor(value) : math::ceiling(value);
}

double math::truncate(double value) {
  return (value > 0) ? math::floor(value) : math::ceiling(value);
}
