#include <xtd/xtd>

using namespace std;
using namespace xtd;

class program {
public:
  static void main() {
    array<uint32_t, 2> years = {2012, 2014};
    console::write_line("Days in the Month for the Gregorian calendar\n");
    console::write_line("{0,-10}{1,-15}{2,4}\n", "Year", "Month", "Days");
    
    for (auto year : years) {
      for (uint32_t ctr = 1; ctr <= 12; ctr++)
        console::write_line("{0,-10}{1,-15}{2,4}", year, static_cast<month_of_year>(ctr), date_time::days_in_month(year, ctr));
      console::write_line();
    }
  }
};

startup_(program);

// This code can produces the following output:
//
//  Days in the Month for the en-US culture using the Gregorian calendar
//
//  Year      Month          Days
//
//  2012      january          31
//  2012      february         29
//  2012      march            31
//  2012      april            30
//  2012      may              31
//  2012      june             30
//  2012      july             31
//  2012      august           31
//  2012      september        30
//  2012      october          31
//  2012      november         30
//  2012      december         31
//
//  2014      january          31
//  2014      february         28
//  2014      march            31
//  2014      april            30
//  2014      may              31
//  2014      june             30
//  2014      july             31
//  2014      august           31
//  2014      september        30
//  2014      october          31
//  2014      november         30
//  2014      december         31
