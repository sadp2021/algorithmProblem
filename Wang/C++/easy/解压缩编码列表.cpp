#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> res;

    for (int i = 0; i < nums.size() / 2; ++i) {
      int x = nums[2 * i], y = nums[2 * i + 1];
      for (int j = 0; j < x; ++j) {
        res.push_back(y);
      }
    }

    return res;
  }
};