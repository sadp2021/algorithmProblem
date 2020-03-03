#include <string>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int distinctEchoSubstrings(string text) {
    int i, len, n = text.size(), count = 0;
    string_view t(text);
    for (len = 1; len <= n / 2 + 1; len++) {
      unordered_set<string_view> set;
      for (i = 0; i <= n - 2 * len; ++i) {
        if (t.substr(i, len) == t.substr(i + len, len))
          set.insert(t.substr(i, len));
      }
      count += set.size();
    }
    return count;
  }
};