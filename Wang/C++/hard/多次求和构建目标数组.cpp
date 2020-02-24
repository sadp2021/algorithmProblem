#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPossible(vector<int>& target) {
    if (target.size() == 1) {
      return target[0] == 1;
    }
    priority_queue<int> heap;
    for (int val : target) {
      if (val <= 0) {
        return false;
      }
      heap.push(val);
    }

    long long tmp_sum = 0;
    for (int val : target) {
      tmp_sum += val;
    }
    while (tmp_sum > target.size()) {
      // 取出最大值
      int top_val = heap.top();
      heap.pop();
      long long tmp_sum_minus = (tmp_sum - top_val);
      if (top_val <= tmp_sum_minus) {
        return false;
      }
      long long scaler = ((long long)top_val - heap.top()) / tmp_sum_minus + 1;
      heap.push(top_val - tmp_sum_minus * scaler);
      tmp_sum -= tmp_sum_minus * scaler;
    }
    return true;
  }
};