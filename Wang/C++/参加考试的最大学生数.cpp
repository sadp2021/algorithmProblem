#include <algorithm>
#include <bitset>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxStudents(vector<vector<char>>& seats) {
    int m = seats.size();
    int n = seats[0].size();

    // 初始化 dp 数组
    vector<vector<int>> dp(m + 1, vector<int>(1 << n));

    for (int row = 1; row <= m; row++) {
      for (int s = 0; s < (1 << n); s++) {
        // 使用 bitset 进行枚举每种排列
        bitset<8> bs(s);
        bool ok = true;
        for (int j = 0; j < n; j++) {
          // 判断椅子状态及左右是否有人
          if ((bs[j] && seats[row - 1][j] == '#') ||
              (j < n - 1 && bs[j] && bs[j + 1])) {
            ok = false;
            break;
          }
        }
        // 说明坐在坏椅子上或相邻坐了, 该状态舍弃
        if (!ok) {
          dp[row][s] = -1;
          continue;
        }
        // 遍历上一行状态查看是否在斜前方
        for (int last = 0; last < (1 << n); last++) {
          if (dp[row - 1][last] == -1) {
            // 上一行的状态被舍弃了，那就直接下一个状态
            continue;
          }
          // 生成上一行状态
          bitset<8> lbs(last);
          bool flag = true;
          for (int j = 0; j < n; j++) {
            if (lbs[j] && ((j > 0 && bs[j - 1]) || (j < n - 1 && bs[j + 1]))) {
              // 如果找到的这个上一行状态的j位置坐了人
              // 下一行的 j + 1 位置或 j - 1
              // 位置也坐了人，那么该状态不合法，舍弃
              flag = false;
              break;
            }
          }
          // flag 为真说明这个 last 状态的每个位置都合法
          if (flag) {
            // 转移方程
            dp[row][s] = max(dp[row][s], dp[row - 1][last] + (int)bs.count());
          }
        }
      }
    }
    int res = 0;
    for (int i = 0; i < (1 << n); i++) {
      // 在最后一行的所有状态中找出最大的
      if (dp[m][i] > res) {
        res = dp[m][i];
      }
    }
    return res;
  }
};