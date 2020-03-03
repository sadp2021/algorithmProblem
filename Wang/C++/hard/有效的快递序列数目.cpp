using LL = long long;

class Solution {
 private:
  static constexpr int mod = 1000000007;

 public:
  int countOrders(int n) {
    if (n == 1) {
      return 1;
    }
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
      ans = (LL)ans * (i * 2 - 1) % mod * i % mod;
    }
    return ans;
  }
};