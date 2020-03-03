class Solution {
 public:
  double angleClock(int hour, int minutes) {
    if (hour == 12) {
      hour = 0;
    }
    if (minutes == 60) {
      minutes = 0;
    }

    double hd = hour * 30 + minutes / 2.0;
    double md = minutes * 6;
    double temp = 0;
    if (hd > md) {
      temp = hd - md;
    } else {
      temp = md - hd;
    }
    if (temp < 180) {
      return temp;
    } else {
      return 360 - temp;
    }
  }
};