#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1, false);
    unordered_set<string> m(wordDict.begin(), wordDict.end());
    dp[0] = true;

    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j <= i; ++j) {
        if (dp[j] && m.find(s.substr(j, i - j + 1)) != m.end()) {
          dp[i + 1] = true;
          break;
        }
      }
    }
    return dp.back();
  }
};