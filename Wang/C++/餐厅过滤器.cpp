#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> filterRestaurants(vector<vector<int>>& restaurants,
                                int veganFriendly, int maxPrice,
                                int maxDistance) {
    vector<vector<int>> res;
    for (auto item : restaurants) {
      if (veganFriendly == 0) {
        if (item[3] <= maxPrice && item[4] <= maxDistance) {
          res.push_back(item);
        }
      } else {
        if (item[3] <= maxPrice && item[4] <= maxDistance && item[2] == 1) {
          res.push_back(item);
        }
      }
    }

    sort(res.begin(), res.end(),
         [](const vector<int>& x, const vector<int>& y) {
           if (x[1] == y[1]) {
             return x[0] > y[0];
           }
           return x[1] > y[1];
         });

    vector<int> data;
    for (auto item : res) {
      data.push_back(item[0]);
    }

    return data;
  }
};