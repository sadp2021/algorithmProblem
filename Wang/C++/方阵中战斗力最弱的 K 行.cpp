#include <algorithm>
#include <vector>

using namespace std;

struct node {
  int row;
  int num;
};

class Solution {
 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<node> count;

    for (int i = 0; i < mat.size(); ++i) {
      int num = 0;
      for (int j = 0; j < mat[i].size(); ++j) {
        if (mat[i][j] == 0) {
          break;
        }
        num++;
      }
      node temp;
      temp.num = num;
      temp.row = i;
      count.push_back(temp);
    }

    sort(count.begin(), count.end(), [](const node& x, const node& y) {
      if (x.num == y.num) {
        return x.row < y.row;
      }
      return x.num < y.num;
    });

    vector<int> res;
    for (int i = 0; i < k; ++i) {
      res.push_back(count[i].row);
    }
    return res;
  }
};