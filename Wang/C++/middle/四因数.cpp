#include <vector>

using namespace std;

class Solution {
 public:
  int sumFourDivisors(vector<int>& nums) {
    int ans = 0;
    for (int num : nums) {
      int factor_cnt = 0, factor_sum = 0;
      for (int i = 1; i * i <= num; ++i) {
        if (num % i == 0) {
          ++factor_cnt;
          factor_sum += i;
          // 判断 i 和 num/i 是否相等，若不相等才能将 num/i
          // 看成新的因数
          if (i * i != num) {
            ++factor_cnt;
            factor_sum += num / i;
          }
        }
      }
      if (factor_cnt == 4) {
        ans += factor_sum;
      }
    }
    return ans;
  }
};