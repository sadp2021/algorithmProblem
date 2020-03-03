#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isZero(int* mem) {
    for (int i = 0; i < 3; ++i) {
      if (mem[i] == 0) {
        return true;
      }
    }
    return false;
  }

  int numberOfSubstrings(string s) {
    int sum = 0;
    int memory[3] = {0, 0, 0};
    int l = 0, r = 2;
    for (int i = 0; i < 3; ++i) {
      memory[s[i] - 'a']++;
    }

    while (l != s.size() - 2) {
      if (isZero(memory)) {
        r++;
        if (r >= s.size()) {
          break;
        }
        memory[s[r] - 'a']++;
      } else {
        sum += s.size() - r;
        memory[s[l] - 'a']--;
        l++;
      }
    }
    return sum;
  }
};