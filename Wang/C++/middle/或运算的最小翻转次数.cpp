#include <bitset>

using namespace std;

class Solution {
 public:
  int minFlips(int a, int b, int c) {
    int sum = 0;
    bitset<32> A(a), B(b), C(c);
    for (int i = 0; i < 32; ++i) {
      if (C[i] == 1) {
        if (A[i] == 0 && B[i] == 0) {
          sum += 1;
        }
      } else {
        if (A[i] == 1) {
          sum += 1;
        }
        if (B[i] == 1) {
          sum += 1;
        }
      }
    }
    return sum;
  }
};