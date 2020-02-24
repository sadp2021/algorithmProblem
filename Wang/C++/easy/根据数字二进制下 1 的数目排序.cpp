#include <algorithm>
#include <bitset>
#include <vector>

using namespace std;

struct node {
  int val;
  int freq;
};

class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    vector<node> temp;
    vector<int> res;
    for (auto item : arr) {
      bitset<32> b(item);
      node n;
      n.val = item;
      n.freq = b.count();
      temp.push_back(n);
    }

    sort(temp.begin(), temp.end(), [](const node& x, const node& y) {
      if (x.freq == y.freq) {
        return x.val < y.val;
      }
      return x.freq < y.freq;
    });

    for (auto item : temp) {
      res.push_back(item.val);
    }

    return res;
  }
};