#include <vector>
using namespace std;

class Solution {
 public:
  int minDifficulty(vector<int>& jobDifficulty, int d) {
    // 不够完成
    if (jobDifficulty.size() < d) {
      return -1;
    }

    vector<vector<int>> dp(d, vector<int>(jobDifficulty.size(), INT_MAX));
    dp[0][0] = jobDifficulty[0];
    for (int j = 1; j < jobDifficulty.size(); j++) {
      dp[0][j] = max(jobDifficulty[j], dp[0][j - 1]);
    }

    for (int i = 1; i < d; i++) {
      dp[i][i] = dp[i - 1][i - 1] + jobDifficulty[i];
      for (int j = i + 1; j < jobDifficulty.size(); j++) {
        int maxJd = 0;
        for (int k = j - 1; k >= i - 1; k--) {
          maxJd = max(maxJd, jobDifficulty[k + 1]);
          dp[i][j] = min(dp[i][j], dp[i - 1][k] + maxJd);
        }
      }
    }
    return dp[d - 1][jobDifficulty.size() - 1];
  }
};