#include <xtd/ustring.h>
#include <xtd/format_exception.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  template <typename Value>
  class test_numeric_parse_string_number;
  
  test_class_attribute<test_numeric_parse_string_number<char>> test_numeric_parse_string_number_class_char_attr {"test_numeric_parse_string_number<char>"};
  test_class_attribute<test_numeric_parse_string_number<unsigned char>> test_numeric_parse_string_number_class_unsigned_char_attr {"test_numeric_parse_string_number<unsigned char>"};
  test_class_attribute<test_numeric_parse_string_number<short>> test_numeric_parse_string_number_class_short_attr {"test_numeric_parse_string_number<short>"};
  test_class_attribute<test_numeric_parse_string_number<unsigned short>> test_numeric_parse_string_number_class_unsigned_short_attr {"test_numeric_parse_string_number<unsigned short>"};
  test_class_attribute<test_numeric_parse_string_number<int>> test_numeric_parse_string_number_class_int_attr {"test_numeric_parse_string_number<int>"};
  test_class_attribute<test_numeric_parse_string_number<unsigned int>> test_numeric_parse_string_number_class_unsigned_int_attr {"test_numeric_parse_string_number<unsigned int>"};
  test_class_attribute<test_numeric_parse_string_number<long>> test_numeric_parse_string_number_class_long_attr {"test_numeric_parse_string_number<long>"};
  test_class_attribute<test_numeric_parse_string_number<unsigned long>> test_numeric_parse_string_number_class_unsigned_long_attr {"test_numeric_parse_string_number<unsigned long>"};
  test_class_attribute<test_numeric_parse_string_number<long long>> test_numeric_parse_string_number_class_long_long_attr {"test_numeric_parse_string_number<long long>"};
  test_class_attribute<test_numeric_parse_string_number<unsigned long long>> test_numeric_parse_string_number_class_unsigned_long_long_attr {"test_numeric_parse_string_number<unsigned long long>"};
  test_class_attribute<test_numeric_parse_string_number<int8_t>> test_numeric_parse_string_number_class_int8_t_attr {"test_numeric_parse_string_number<int8_t>"};
  test_class_attribute<test_numeric_parse_string_number<int16_t>> test_numeric_parse_string_number_class_int16_t_attr {"test_numeric_parse_string_number<int16_t>"};
  test_class_attribute<test_numeric_parse_string_number<int32_t>> test_numeric_parse_string_number_class_int32_t_attr {"test_numeric_parse_string_number<int32_t>"};
  test_class_attribute<test_numeric_parse_string_number<int64_t>> test_numeric_parse_string_number_class_int64_t_attr {"test_numeric_parse_string_number<int64_t>"};
  test_class_attribute<test_numeric_parse_string_number<intptr_t>> test_numeric_parse_string_number_class_intptr_t_attr {"test_numeric_parse_string_number<intptr_t>"};
  test_class_attribute<test_numeric_parse_string_number<ptrdiff_t>> test_numeric_parse_string_number_class_ptrdiff_t_attr {"test_numeric_parse_string_number<ptrdiff_t>"};
  test_class_attribute<test_numeric_parse_string_number<size_t>> test_numeric_parse_string_number_class_size_t_attr {"test_numeric_parse_string_number<size_t>"};
  test_class_attribute<test_numeric_parse_string_number<uint8_t>> test_numeric_parse_string_number_class_uint8_t_attr {"test_numeric_parse_string_number<uint8_t>"};
  test_class_attribute<test_numeric_parse_string_number<uint16_t>> test_numeric_parse_string_number_class_uint16_t_attr {"test_numeric_parse_string_number<uint16_t>"};
  test_class_attribute<test_numeric_parse_string_number<uint32_t>> test_numeric_parse_string_number_class_uint32_t_attr {"test_numeric_parse_string_number<uint32_t>"};
  test_class_attribute<test_numeric_parse_string_number<uint64_t>> test_numeric_parse_string_number_class_uint64_t_attr {"test_numeric_parse_string_number<uint64_t>"};
  test_class_attribute<test_numeric_parse_string_number<uintptr_t>> test_numeric_parse_string_number_class_uintptr_t_attr {"test_numeric_parse_string_number<uintptr_t>"};
  
  template <typename Value>
  class test_numeric_parse_string_number : public test_class {
  public:
    static void class_initialize_(class_initialize) {
      std::locale::global(std::locale("en_US.UTF-8"));
    }
    
    void test_method_(parse_styles_number) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42", number_styles::number), csf_);
    }
    
    void test_method_(parse_styles_number_with_leading_white_spaces) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>(" \f\n\r\t\v42", number_styles::number), csf_);
    }
    
    void test_method_(parse_styles_number_with_trailing_white_spaces) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42 \f\n\r\t\v", number_styles::number), csf_);
    }
    
    void test_method_(parse_styles_number_with_leading_plus_sign) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("+42", number_styles::number), csf_);
    }
    
    void test_method_(parse_styles_number_with_two_leading_plus_sign) {
      assert::throws<format_exception>([] {xtd::parse<Value>("++42", number_styles::number);}, csf_);
    }
    
    void test_method_(parse_styles_number_with_leading_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::are_equal(static_cast<Value>(-42), xtd::parse<Value>("-42", number_styles::number), csf_);
      else
        assert::throws<format_exception>([] {xtd::parse<Value>("-42", number_styles::number);}, csf_);
    }
    
    void test_method_(parse_styles_number_with_two_leading_minus_sign) {
      assert::throws<format_exception>([] {xtd::parse<Value>("--42", number_styles::number);}, csf_);
    }
    
    void test_method_(parse_styles_number_with_trailing_plus_sign) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42+", number_styles::number), csf_);
    }
    
    void test_method_(parse_styles_number_with_two_trailing_plus_sign) {
      assert::throws<format_exception>([] {xtd::parse<Value>("42++", number_styles::number);}, csf_);
    }
    
    void test_method_(parse_styles_number_with_trailing_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::are_equal(static_cast<Value>(-42), xtd::parse<Value>("42-", number_styles::number), csf_);
      else
        assert::throws<format_exception>([] {xtd::parse<Value>("42-", number_styles::number);}, csf_);
    }
    
    void test_method_(parse_styles_number_with_two_trailing_minus_sign) {
      assert::throws<format_exception>([] {xtd::parse<Value>("42--", number_styles::number);}, csf_);
    }
    
    void test_method_(parse_styles_number_with_parentheses) {
      if (std::is_signed<Value>::value)
        assert::throws<format_exception>([] {xtd::parse<Value>("(42)", number_styles::number);}, csf_);
      else
        assert::throws<format_exception>([] {xtd::parse<Value>("(42)", number_styles::number);}, csf_);
    }
    
    void test_method_(parse_styles_number_with_two_parentheses) {
      assert::throws<format_exception>([] {xtd::parse<Value>("((42))", number_styles::number);}, csf_);
    }
    
    void test_method_(parse_styles_number_with_decimal_point) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42.0", number_styles::number), csf_);
    }
    
    void test_method_(parse_styles_number_with_two_decimal_point) {
      assert::throws<format_exception>([] {xtd::parse<Value>("4.2.0", number_styles::number);}, csf_);
    }
    
    void test_method_(parse_styles_number_with_thousands) {
      if (!std::is_same<Value, int8_t>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::are_equal(static_cast<Value>(1234), xtd::parse<Value>("1,234", number_styles::number), csf_);
    }
    
    void test_method_(parse_styles_number_with_two_thousands) {
      if (!std::is_same<Value, int8_t>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::throws<format_exception>([] {xtd::parse<Value>("1,,234", number_styles::number);}, csf_);
    }
    
    void test_method_(parse_styles_number_with_exponent) {
      assert::throws<format_exception>([] {xtd::parse<Value>("4E+01", number_styles::number);}, csf_);
    }
    
    void test_method_(parse_styles_number_with_leading_currency_symbol) {
      assert::throws<format_exception>([] {xtd::parse<Value>("$42", number_styles::number);}, csf_);
    }
    
    void test_method_(parse_styles_number_with_trailing_currency_symbol) {
      assert::throws<format_exception>([] {xtd::parse<Value>("42$", number_styles::number);}, csf_);
    }
    
    void test_method_(parse_styles_number_with_binary_specifier) {
      assert::throws<format_exception>([] {xtd::parse<Value>("0b101010", number_styles::number);}, csf_);
    }
    
    void test_method_(parse_styles_number_with_octal_specifier) {
      assert::are_equal(static_cast<Value>(52), xtd::parse<Value>("052", number_styles::number), csf_);
    }
    
    void test_method_(parse_styles_number_with_hexa_specifier) {
      assert::throws<format_exception>([] {xtd::parse<Value>("0x2A", number_styles::number);}, csf_);
    }
    
    void test_method_(parse_styles_number_invalid) {
      assert::throws<format_exception>([] {xtd::parse<Value>("z42", number_styles::number);}, csf_);
    }
  };
}
