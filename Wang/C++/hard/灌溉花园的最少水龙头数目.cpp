#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minTaps(int n, vector<int>& ranges) {
    vector<int> dp(10100, INT32_MAX - 1);
    dp[0] = 0;
    for (int i = 0; i < ranges.size(); i++) {
      int l = max(0, i - ranges[i]);
      int r = min(n, i + ranges[i]);
      for (int j = l; j <= r; j++) {
        dp[j] = min(dp[j], dp[l] + 1);
      }
    }
    return dp[n] == INT32_MAX - 1 ? -1 : dp[n];
  }
};