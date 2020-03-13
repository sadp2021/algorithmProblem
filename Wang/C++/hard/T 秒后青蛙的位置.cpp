#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    unordered_map<int, int> fa, c;

    for (auto& x : edges) {
      sort(x.begin(), x.end());
      fa[x[1]] = x[0];
      c[x[0]]++;
    }

    double ans = 1;
    int cur = target, cnt = 0;
    while (fa[cur]) {
      ans /= (double)c[fa[cur]];
      cur = fa[cur];
      cnt++;
    }

    if (cnt == t) {
      return ans;
    }
    if (cnt < t) {
      return c[target] ? 0 : ans;
    }
    return 0;
  }
};