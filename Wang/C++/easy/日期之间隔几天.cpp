#include <string>

using namespace std;

class Solution {
 public:
  int tab[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int isleap(int y) { return y % 4 == 0 && y % 100 != 0 || y % 400 == 0; }

  int getdate(const char *date) {
    int y, m, d, r = 0;
    sscanf(date, "%d-%d-%d", &y, &m, &d);
    for (int i = 1970; i < y; i++)
      if (isleap(i))
        r += 366;
      else
        r += 365;
    for (int i = 1; i < m; i++) {
      r += tab[i];
      if (i == 2 && isleap(y)) r += 1;
    }
    r += d;
    return r;
  }

  int daysBetweenDates(string date1, string date2) {
    int days = getdate(date1.c_str()) - getdate(date2.c_str());
    if (days < 0) {
      days = -days;
    }
    return days;
  }
};