#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); ++i) {
      m[nums[i]]++;
    }

    for (auto& item : m) {
      if (item.second == 1) {
        return item.first;
      }
    }

    return 0;
  }
};