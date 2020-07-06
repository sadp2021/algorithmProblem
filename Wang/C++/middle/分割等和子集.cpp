#include <vector>

using namespace std;

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int item : nums) {
      sum += item;
    }

    if (sum & 1 == 1) {
      return false;
    }
    sum /= 2;

    vector<vector<bool> > dp(nums.size() + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i < nums.size() + 1; ++i) {
      dp[i][0] = true;
    }

    for (int i = 1; i < nums.size() + 1; ++i) {
      for (int j = 1; j < sum + 1; ++j) {
        if (j - nums[i - 1] < 0) {
          // 背包容量不足，不能装入第 i 个物品
          dp[i][j] = dp[i - 1][j];
        } else {
          // 装入或不装入背包
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
        }
      }
    }

    return dp[nums.size()][sum];
  }
};