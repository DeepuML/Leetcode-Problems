class Solution {
public:
    bool can_place(int r, int c, vector<vector<int>> &board){
        // same column  
        int i=r;
        int j=c;
        while(i>=0){
            if(board[i][j]=='Q'){
            return false;
            }
            i--;
        }
        
        // diagonal 1
         i=r-1;
         j=c-1;
         while(i>=0 && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
         }

        // diagonal 2
         i=r-1;
         j=c+1;
          while(i>=0 && j<board.size()){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
         }
         return true;
    }

    int solve(int i, vector<vector<int>> &board){
        if(i==board.size()){
            return 1;
        }

        int count =0 ;
        for(int j=0;j<board.size();j++){
            if(can_place(i,j, board)){
                board[i][j]='Q';
                count = count + solve(i+1, board);
                board[i][j]='.';
            }
        }
        return count;
    }

    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, '.'));
        return solve(0, board);
    }
};