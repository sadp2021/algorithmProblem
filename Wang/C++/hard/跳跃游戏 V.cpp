#include <queue>
#include <vector>

using namespace std;

struct node {
  int count;
  int pos;
};

class Solution {
 public:
  // vector<int> mem;
  // int d, n;

  // int dfs(int cur, vector<int>& arr) {
  //   if (mem[cur] != 0) {
  //     return mem[cur];
  //   }
  //   int ret = 1;
  //   for (int j = cur + 1; j <= min(n - 1, cur + d) && arr[j] < arr[cur]; j++)
  //   {
  //     ret = max(ret, dfs(j, arr) + 1);
  //   }
  //   for (int j = cur - 1; j >= max(0, cur - d) && arr[j] < arr[cur]; j--) {
  //     ret = max(ret, dfs(j, arr) + 1);
  //   }
  //   return mem[cur] = ret;
  // }
  // int maxJumps(vector<int>& arr, int d) {
  //   this->d = d;
  //   n = arr.size();
  //   mem = vector<int>(n);

  //   int ret = 0;
  //   for (int i = 0; i < n; i++) {
  //     ret = max(ret, dfs(i, arr));
  //   }
  //   return ret;
  // }
  int maxJumps(vector<int>& arr, int d) {
    int res = 1;
    vector<int> mem(arr.size(), 0);
    if (arr.size() == 1) {
      return res;
    }

    for (int i = 0; i < arr.size(); ++i) {
      queue<node> q;
      node start;
      start.pos = i;
      start.count = 1;
      q.push(start);

      while (!q.empty()) {
        node temp = q.front();
        q.pop();
        if (mem[temp.pos] != 0) {
          mem[i] = temp.count + mem[temp.pos] - 1;
          break;
        }

        for (int j = 1; j <= d; ++j) {
          if (temp.pos - j < 0 || arr[temp.pos] <= arr[temp.pos - j]) {
            break;
          }
          node n;
          n.pos = temp.pos - j;
          n.count = temp.count + 1;
          q.push(n);
        }
        for (int j = 1; j <= d; ++j) {
          if (temp.pos + j >= arr.size() ||
              arr[temp.pos] <= arr[temp.pos + j]) {
            break;
          }
          node n;
          n.pos = temp.pos + j;
          n.count = temp.count + 1;
          q.push(n);
        }

        if (q.empty()) {
          mem[i] = temp.count;
        }
      }
    }

    for (auto item : mem) {
      if (item > res) {
        res = item;
      }
    }

    return res;
  }
};