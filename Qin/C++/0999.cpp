class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x, y, ans = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 'R'){
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        // up
        for(int i = x - 1; i >= 0; i--){
            if(board[i][y] == 'B'
                    || board[i][y] == 'b' 
                    || board[i][y] == 'P') break;
            else if(board[i][y] == 'p'){
                ans++;
                break;
            }
        }

        // down
        for(int i = x + 1; i < 8; i++){
            if(board[i][y] == 'B'
                    || board[i][y] == 'b' 
                    || board[i][y] == 'P') break;
            else if(board[i][y] == 'p'){
                ans++;
                break;
            }
        }
        
        // left
        for(int i = y - 1; i >= 0; i--){
            if(board[x][i] == 'B'
                    || board[x][i] == 'b' 
                    || board[x][i] == 'P') break;
            else if(board[x][i] == 'p'){
                ans++;
                break;
            }
        }


        // right
        for(int i = y + 1; i < 8; i++){
            if(board[x][i] == 'B'
                    || board[x][i] == 'b' 
                    || board[x][i] == 'P') break;
            else if(board[x][i] == 'p'){
                ans++;
                break;
            }
        } 

        return ans;
    }
};
