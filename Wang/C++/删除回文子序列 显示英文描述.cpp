#include <string>

using namespace std;

class Solution {
 public:
  int removePalindromeSub(string s) {
    if (s.size() == 0) {
      return 0;
    }

    for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
      if (s[l] != s[r]) {
        return 2;
      }
    }

    return 1;
  }
};