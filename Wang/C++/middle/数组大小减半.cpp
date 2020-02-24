#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> m;
    vector<int> t;
    for (int i = 0; i < arr.size(); i++) {
      m[arr[i]]++;
    }

    for (auto iter = m.begin(); iter != m.end(); ++iter) {
      t.push_back(iter->second);
    }
    sort(t.begin(), t.end());

    int res = 0, len = arr.size();
    for (int i = t.size() - 1; i >= 0; i--) {
      len -= t[i];
      res++;
      if (len <= arr.size() / 2) {
        return res;
      }
    }
    return res;
  }
};