#include <vector>

using namespace std;

class Solution {
 public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    int data = 0;
    int min = INT32_MAX;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    vector<vector<int>> res(n, vector<int>());
    for (auto item : edges) {
      matrix[item[0]][item[1]] = item[2];
      matrix[item[1]][item[0]] = item[2];
    }

    for (int i = 0; i < n; ++i) {
      vector<int> dis(n, INT32_MAX);
      vector<bool> visit(n, false);
      dis[i] = 0;

      for (int j = 0; j < n - 1; ++j) {
        int pos;
        int minDis = INT32_MAX;
        // 找出最小值
        for (int k = 0; k < n; ++k) {
          if (dis[k] < minDis && !visit[k]) {
            pos = k;
            minDis = dis[k];
          }
        }
        visit[pos] = true;
        // 从最小值点出发
        for (int k = 0; k < n; ++k) {
          if (dis[pos] + matrix[pos][k] < dis[k] && matrix[pos][k] != 0 &&
              !visit[k]) {
            dis[k] = dis[pos] + matrix[pos][k];
          }
        }
      }
      int count = 0;
      for (auto item : dis) {
        if (item <= distanceThreshold) {
          count++;
        }
      }
      if (count <= min) {
        data = i;
        min = count;
      }
    }

    return data;
  }
};