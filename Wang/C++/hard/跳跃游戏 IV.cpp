#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct node {
  int count;
  int position;
  int value;
};

class Solution {
 public:
  int minJumps(vector<int>& arr) {
    int pre = arr[0];
    vector<bool> visit(arr.size(), false);
    queue<node> q;
    unordered_map<int, vector<int>> m;
    m[arr[0]].push_back(0);
    for (int i = 1; i < arr.size(); ++i) {
      if (arr[i] == pre) {
        m[arr[i]].pop_back();
      }
      m[arr[i]].push_back(i);
      pre = arr[i];
    }

    node start;
    start.count = 0;
    start.position = 0;
    start.value = arr[0];
    visit[0] = true;
    q.push(start);

    while (!q.empty()) {
      node temp = q.front();
      q.pop();

      if (temp.position == arr.size() - 1) {
        return temp.count;
      }

      if (temp.position - 1 > 0 && !visit[temp.position - 1]) {
        node next;
        next.position = temp.position - 1;
        next.count = temp.count + 1;
        next.value = arr[temp.position - 1];
        visit[temp.position - 1] = true;
        q.push(next);
      }

      if (temp.position + 1 < arr.size() && !visit[temp.position + 1]) {
        node next;
        next.position = temp.position + 1;
        next.count = temp.count + 1;
        next.value = arr[temp.position + 1];
        visit[temp.position + 1] = true;
        q.push(next);
      }

      vector<int> positions = m[temp.value];

      for (int i = 0; i < positions.size(); ++i) {
        if (!visit[positions[i]]) {
          node next;
          next.position = positions[i];
          next.count = temp.count + 1;
          next.value = temp.value;
          visit[positions[i]] = true;
          q.push(next);
        }
      }
    }
    return 0;
  }
};