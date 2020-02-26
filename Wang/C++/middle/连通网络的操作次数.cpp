#include <numeric>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<int> fa;

  int findSet(int start) {
    if (start != fa[start]) {
      fa[start] = findSet(fa[start]);
    }

    return fa[start];
  }

 public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) {
      return -1;
    }

    fa.resize(n);
    // +1 赋值
    iota(fa.begin(), fa.end(), 0);

    int count = n;
    for (auto& item : connections) {
      int x = findSet(item[0]), y = findSet(item[1]);
      if (x != y) {
        count--;
        fa[y] = x;
      }
    }
    return count - 1;
  }
};