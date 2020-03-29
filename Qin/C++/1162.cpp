#include <vector>
#include <utility>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // triversal
        int N = grid.size();
        queue<pair<int, int>> Q;
        vector<vector<bool>> visit(N);
        for(int i = 0; i < N; i++) visit.push_back(vector<bool>(false));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; i++){
                if(grid[i][j] == 1) Q.push(make_pair(i, j));
            }
        }

        // All is same
        if(Q.size() == N * N || Q.size() == 0) return 0;

    }

    int BFS(vector<vector<int>>& grid, vector<vector<bool>>& visit, queue<pair<int, int>>& Q){
        int N = grid.size();
        int Max = 0;
        while(!Q.empty()){
            pair<int, int> handle = Q.front();
            int x = handle.first, y = handle.second;
            int now_step = grid[x][y] + 1;
            bool inc = false;
            Q.pop();
    
            if(x-1 >= 0 && grid[x-1][y] == 0) grid[x-1][y] = now_step; inc = true;
            if(x+1 < N && grid[x+1][y] == 0) grid[x+1][y] = now_step; inc = true;
            if(y-1 >= 0 && grid[x][y-1] == 0) grid[x][y-1] = now_step; inc = true;
            if(y+1 < N && grid[x][y+1] == 0) grid[x][y+1] = now_step; inc = true;

            if(inc) Max = max(Max, now_step);
        }

        return Max;
    }
};


int main(){
    Solution s;
    vector<vector<int>> sample = {{1,0,1},{0,0,0},{1,0,1}};
    cout << s.maxDistance(sample) << endl;
    return 0;
}