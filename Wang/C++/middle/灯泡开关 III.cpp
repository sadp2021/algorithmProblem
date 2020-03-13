#include <vector>

using namespace std;

class Solution {
 public:
  int numTimesAllBlue(vector<int>& light) {
    int m = 1, cnt = 0;
    for (int i = 0; i < light.size(); i++) {
      m = max(light[i], m);
      if (m == i + 1) cnt++;
    }
    return cnt;
  }
};