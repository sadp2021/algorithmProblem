#include <vector>

using namespace std;

class CustomStack {
  vector<int> stack;
  int index;

 public:
  CustomStack(int maxSize) {
    stack.resize(maxSize);
    index = -1;
  }

  void push(int x) {
    if (index == stack.size() - 1) {
      return;
    }
    stack[++index] = x;
  }

  int pop() {
    if (index == -1) {
      return -1;
    }
    return stack[index--];
  }

  void increment(int k, int val) {
    int temp = min(k, index + 1);
    for (int i = 0; i < temp; ++i) {
      stack[i] += val;
    }
  }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */