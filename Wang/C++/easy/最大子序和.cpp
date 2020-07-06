#include <climits>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); ++i) {
      dp[i] = max(dp[i], dp[i] + dp[i - 1]);
    }

    int res = INT_MIN;
    for (auto& item : dp) {
      res = max(res, item);
    }

    return res;
  }
};