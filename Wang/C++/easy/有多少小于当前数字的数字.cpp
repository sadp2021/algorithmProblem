#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> res;

    for (int i = 0; i < nums.size(); ++i) {
      int number = nums[i], count = 0;
      for (int j = 0; j < nums.size(); ++j) {
        if (nums[j] < number) {
          count++;
        }
      }
      res.push_back(count);
    }

    return res;
  }
};