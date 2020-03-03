#include <bitset>
#include <vector>

using namespace std;

class Solution {
 public:
  int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int sum = 0, res = 0;
    for (int i = 0; i < k; i++) {
      sum += arr[i];
    }
    if (sum >= threshold * k) {
      res++;
    }
    for (int i = k; i < arr.size(); i++) {
      sum += (arr[i] - arr[i - k]);
      if (sum >= threshold * k) {
        res++;
      }
    }
    return res;
  }
};