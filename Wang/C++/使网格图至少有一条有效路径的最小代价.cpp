#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int xLength, yLength;
  vector<vector<int>> dp;
  void dfs(int x, int y, int count, vector<vector<int>>& grid) {
    if (x < 0 || y < 0 || x >= xLength || y >= yLength || count == dp[x][y]) {
      return;
    }

    dp[x][y] = min(dp[x][y], count);
    if (grid[x][y] == 1) {
      y++;
    } else if (grid[x][y] == 2) {
      y--;
    } else if (grid[x][y] == 3) {
      x++;
    } else {
      x--;
    }
    dfs(x, y, count, grid);
    return;
  }

 public:
  int minCost(vector<vector<int>>& grid) {
    xLength = grid.size();
    yLength = grid[0].size();
    dp = vector(xLength, vector<int>(yLength, INT32_MAX >> 1));
    dp[0][0] = 0;
    for (int j = 0; j < yLength; ++j) {
      dfs(0, j, dp[0][j], grid);
    }

    for (int i = 1; i < xLength; ++i) {
      for (int j = 0; j < yLength; ++j) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
      }
      for (int j = 0; j < yLength; ++j) {
        dfs(i, j, dp[i][j], grid);
      }
    }

    return dp[xLength - 1][yLength - 1];
  }
};