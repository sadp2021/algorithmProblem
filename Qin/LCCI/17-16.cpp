#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int massage(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size);
        
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        if(size == 2) return max(nums[0], nums[1]);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < size; i++){
            // pick or not
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        return dp[size - 1];
    }
};


int main(){
    Solution s;
    vector<int> sample = {1, 2, 3, 1};
    cout << s.massage(sample) << endl;
    return 0;
}

