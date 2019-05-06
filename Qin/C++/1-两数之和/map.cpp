#include <iostream>
#include <vector>
#include <map> 
using namespace std;

int main(){
	vector<int> nums,ans;
	map<int,int> m;
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
		//先从map里面找有没有对应的
		if(m.find(target-nums[i]) == m.end()){
			//没有就添加
			m[nums[i]] = i; 
		} else {
			//有
			ans.push_back(m[target-nums[i]]);
			ans.push_back(i);
			break; 
		}
	}
	
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << ' ';
	}
}

