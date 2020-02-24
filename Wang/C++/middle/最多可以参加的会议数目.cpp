#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxEvents(vector<vector<int>> &events) {
    sort(events.begin(), events.end(),
         [](const vector<int> &e1, const vector<int> &e2) {
           return e1[1] < e2[1];
         });
    unordered_set<int> record;

    for (vector<int> e : events) {
      for (int i = e[0]; i <= e[1]; ++i) {
        if (record.find(i) == record.end()) {
          record.insert(i);
          break;
        }
      }
    }

    return record.size();
  }
};