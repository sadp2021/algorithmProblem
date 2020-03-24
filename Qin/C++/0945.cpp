#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() <= 1) return 0;
        int count = 0, min = A[0];
        sort(A.begin(), A.end());
        
        for(int i = 1; i < A.size(); i++){
            if(A[i] <= A[i-1]) {
                count += (A[i-1] + 1) - A[i];
                A[i] = A[i-1] + 1;
            }
        }
        return count;
    }
};


int main(){
    Solution s;
    vector<int> sample = {1, 2, 2};
    cout << s.minIncrementForUnique(sample) << endl;
    return 0;
}
