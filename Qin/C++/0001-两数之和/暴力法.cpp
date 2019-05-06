#include <iostream>
#include <vector>
using namespace std;
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        vector<int> ans;
//        for(int i = 0; i < nums.size(); i++){
//        	
//		}
//    }
//};

int main(){
	vector<int> nums,ans;
	int target;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		nums.push_back(t);
	}
	cin >> target;
	
	for(int i = 0; i < nums.size(); i++){
		int k = nums[i];
		for(int j = i+1; j < nums.size(); j++){
			if(nums[j] > target - k) continue;
			if(k + nums[j] == target){
				ans.push_back(i);
				ans.push_back(j);
				break;
			}
		}
		if(!ans.empty()) break;
	}
	
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << ' ';
	}
}

