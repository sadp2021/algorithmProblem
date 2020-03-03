#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
	public:
		bool checkIfExist(vector<int>& arr) {
			set<double> s;

			for (int i = 0; i < arr.size(); ++i) {
				if (s.find(arr[i]) != s.end()) {
					return true;
				}
				s.insert(arr[i] * 2);
				if (arr[i] % 2 == 0) {
					s.insert(arr[i] / 2);
				}
			}

			return false;
		}
};

int main() {
	Solution s = Solution();
	vector<int> v({3, 1, 7, 11});
	cout << s.checkIfExist(v);
}
