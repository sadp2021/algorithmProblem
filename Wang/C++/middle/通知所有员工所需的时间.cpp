#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class MySolution {
 public:
  int numOfMinutes(int n, int headID, vector<int>& manager,
                   vector<int>& informTime) {
    vector<int> length(n, 0);
    unordered_map<int, vector<int>> m;

    for (int i = 0; i < n; ++i) {
      if (manager[i] != -1) {
        m[manager[i]].push_back(i);
      }
    }

    queue<int> q;
    q.push(headID);

    while (!q.empty()) {
      int temp = q.front();
      q.pop();

      for (int i = 0; i < m[temp].size(); ++i) {
        q.push(m[temp][i]);
        length[m[temp][i]] += (length[temp] + informTime[temp]);
      }
    }
    int max = INT32_MIN;
    for (auto item : length) {
      if (item > max) {
        max = item;
      }
    }

    return max;
  }
};

class Solution {
 public:
  int numOfMinutes(int n, int headID, vector<int>& manager,
                   vector<int>& informTime) {
    if (n <= 1) return 0;

    int max_time = 0;
    for (int i = 0; i < n; i++) {
      if (informTime[i] == 0) {  //此人是底层人员
        int time = 0, lead = manager[i];
        while (lead != headID) {
          time += informTime[lead];
          lead = manager[lead];
        }
        time += informTime[headID];
        if (time > max_time) max_time = time;
      }
    }
    return max_time;
  }
};
