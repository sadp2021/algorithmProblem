#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string alphabetBoardPath(string target) {
    int x = 0, y = 0, nx = 0, ny = 0;
    string ans = "";

    for (int i = 0; i < target.size(); i++) {
      int temp = target[i] - 'a';
      if (i > 0 && target[i] == target[i - 1]) {
        ans += '!';
      } else {
        nx = temp / 5;
        ny = temp % 5;
        if (ny < y) {
          for (int z = 0; z < y - ny; z++) ans += "L";
        }
        if (nx < x) {
          for (int z = 0; z < x - nx; z++) ans += "U";
        }
        if (nx > x) {
          for (int z = 0; z < nx - x; z++) ans += "D";
        }
        if (ny > y) {
          for (int z = 0; z < ny - y; z++) ans += "R";
        }

        ans.append("!");
        x = nx;
        y = ny;
      }
    }
    return ans;
  }
};