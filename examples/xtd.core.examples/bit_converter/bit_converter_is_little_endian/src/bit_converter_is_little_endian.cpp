#include <xtd/xtd>

using namespace xtd;

namespace examples {
  class program {
  public:
    // The main entry point for the application.
    static void main() {
      console::write_line(
        "This example of the bit_converter::is_little_endian field "
        "generates \nthe following output when run on "
        "x86-class computers.\n");
      console::write_line("is_little_endian:  {0}",
        bit_converter::is_little_endian);
    }
  };
}

startup_(examples::program);

/*
 This example of the bit_converter::is_little_endian field generates
 the following output when run on x86-class computers.

 is_little_endian:  true
 */
