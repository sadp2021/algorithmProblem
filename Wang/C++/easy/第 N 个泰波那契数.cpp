#include <unordered_map>

using namespace std;

class Solution {
 private:
  unordered_map<int, int> m;

 public:
  int tribonacci(int n) {
    if (n == 0) {
      return 0;
    }
    if (n == 1 || n == 2) {
      return 1;
    }
    if (m.find(n) != m.end()) {
      return m[n];
    }

    int temp[] = {tribonacci(n - 1), tribonacci(n - 2), tribonacci(n - 3)};

    for (int i = 0; i < 3; ++i) {
      m.insert(pair<int, int>(n - 1 - i, temp[i]));
    }

    return temp[0] + temp[1] + temp[2];
  }
};