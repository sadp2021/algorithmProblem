#include <vector>

using namespace std;

struct node {
  int val;
  int index;
  int order;
};

class Solution {
 public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> res;
    if (arr.size() == 0) {
      return res;
    }
    vector<node> temp;

    for (int i = 0; i < arr.size(); ++i) {
      node n;
      n.val = arr[i];
      n.index = i;
      temp.push_back(n);
    }
    sort(temp.begin(), temp.end(),
         [](const node& x, const node& y) { return x.val < y.val; });

    int index = 2;
    temp[0].order = 1;
    for (int i = 1; i < arr.size(); ++i) {
      if (temp[i].val == temp[i - 1].val) {
        temp[i].order = temp[i - 1].order;
      } else {
        temp[i].order = index++;
      }
    }
    sort(temp.begin(), temp.end(),
         [](const node& x, const node& y) { return x.index < y.index; });

    for (auto item : temp) {
      res.push_back(item.order);
    }

    return res;
  }
};