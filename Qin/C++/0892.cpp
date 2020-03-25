class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int N = grid.size();
        if(N == 1) return grid[0][0] == 0 ? 0 : grid[0][0] * 4 + 2;
        int ans = 0;

        // corner
        ans += grid[0][0] == 0 ? 0 : (2 + max(0, grid[0][0] - grid[0][1])
            + max(0, grid[0][0] - grid[1][0])
            + grid[0][0] * 2);
        ans += grid[0][N-1] == 0 ? 0 : (2 + max(0, grid[0][N-1] - grid[0][N-2])
            + max(0, grid[0][N-1] - grid[1][N-1])
            + grid[0][N-1] * 2);
        ans += grid[N-1][0] == 0 ? 0 : (2 + max(0, grid[N-1][0] - grid[N-2][0])
            + max(0, grid[N-1][0] - grid[N-1][1])
            + grid[N-1][0] * 2);
        ans += grid[N-1][N-1] == 0 ? 0 : (2 + max(0, grid[N-1][N-1] - grid[N-1][N-2])
            + max(0, grid[N-1][N-1] - grid[N-2][N-1])
            + grid[N-1][N-1] * 2);
        for(int i = 1; i < N - 1; i++){
            ans += grid[0][i] == 0 ? 0 : (2 + max(0, grid[0][i] - grid[0][i-1])
                + max(0, grid[0][i] - grid[0][i+1])
                + max(0, grid[0][i] - grid[1][i])
                + grid[0][i]);
            ans += grid[N-1][i] == 0 ? 0 : (2 + max(0, grid[N-1][i] - grid[N-1][i-1])
                + max(0, grid[N-1][i] - grid[N-1][i+1])
                + max(0, grid[N-1][i] - grid[N-2][i])
                + grid[N-1][i]);
        }
        for(int i = 1; i < N - 1; i++){
            ans += grid[i][0] == 0 ? 0 : (2 + max(0, grid[i][0] - grid[i-1][0])
                + max(0, grid[i][0] - grid[i+1][0])
                + max(0, grid[i][0] - grid[i][1])
                + grid[i][0]);
            ans += grid[i][N-1] == 0 ? 0 : (2 + max(0, grid[i][N-1] - grid[i-1][N-1])
                + max(0, grid[i][N-1] - grid[i+1][N-1])
                + max(0, grid[i][N-1] - grid[i][N-2])
                + grid[i][N-1]);
        }
        for(int i = 1; i < N - 1; i++){
            for(int j = 1; j < N - 1; j++){
                ans += grid[i][j] == 0 ? 0 : (2 + max(0, grid[i][j] - grid[i-1][j])
                    + max(0, grid[i][j] - grid[i+1][j])
                    + max(0, grid[i][j] - grid[i][j-1])
                    + max(0, grid[i][j] - grid[i][j+1]));
            }
        }
        return ans;
    }
};
