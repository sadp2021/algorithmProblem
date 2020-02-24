#include <vector>

using namespace std;

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    vector<vector<long long>> dp(row, vector<long long>(col, 0));

    dp[0][0] = 1;
    if (obstacleGrid[0][0] == 1) {
      dp[0][0] = 0;
    }
    for (int i = 1; i < col; ++i) {
      if (obstacleGrid[0][i] == 1 || dp[0][i - 1] == 0) {
        dp[0][i] = 0;
      } else {
        dp[0][i] = 1;
      }
    }

    for (int i = 1; i < row; ++i) {
      if (obstacleGrid[i][0] == 1 || dp[i - 1][0] == 0) {
        dp[i][0] = 0;
      } else {
        dp[i][0] = 1;
      }
    }

    for (int i = 1; i < row; ++i) {
      for (int j = 1; j < col; ++j) {
        if (obstacleGrid[i][j] == 1) {
          dp[i][j] = 0;
          continue;
        }
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    return dp[row - 1][col - 1];
  }
};