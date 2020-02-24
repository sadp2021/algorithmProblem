#include <vector>

using namespace std;

class ProductOfNumbers {
 private:
  vector<int> list;

 public:
  ProductOfNumbers() {}

  void add(int num) { list.push_back(num); }

  int getProduct(int k) {
    int res = 1;
    int length = list.size();
    if (length == 0) {
      return 0;
    }
    for (int i = 0; i < k; ++i) {
      if (res == 0) {
        return 0;
      }
      res *= list[length - k + i];
    }

    return res;
  }
};