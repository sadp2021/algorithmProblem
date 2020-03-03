#include <algorithm>
#include <vector>

using namespace std;

// class Solution {
//  public:
//   vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
//     vector<vector<int>> a(mat.size(), vector<int>(mat[0].size()));
//     for (int r = 0; r < mat.size(); ++r) {
//       for (int c = 0; c < mat[0].size(); ++c) {
//         for (int rr = max(0, r - K); rr <= min(int(mat.size() - 1), r + K);
//         ++rr) {
//           for (int cc = max(c - K, 0);
//                cc <= min(int(mat[0].size()) - 1, c + K); ++cc) {
//             a[r][c] += mat[rr][cc];
//           }
//         }
//       }
//     }
//     return a;
//   }
// };

class Solution {
 public:
  int get(const vector<vector<int>>& pre, int m, int n, int x, int y) {
    x = max(min(x, m), 0);
    y = max(min(y, n), 0);
    return pre[x][y];
  }

  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> P(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        P[i][j] =
            P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
      }
    }

    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans[i][j] = get(P, m, n, i + K + 1, j + K + 1) -
                    get(P, m, n, i - K, j + K + 1) -
                    get(P, m, n, i + K + 1, j - K) + get(P, m, n, i - K, j - K);
      }
    }
    return ans;
  }
};
