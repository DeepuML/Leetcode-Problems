class Solution {
public:

    bool isSafe(int row, int col, vector<string> &board, int n) {
        
        // check row (previous columns only)
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 'Q')
                return false;
        }

        // check upper-left diagonal
        int r = row - 1, c = col - 1;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }

        // check lower-left diagonal
        r = row + 1;
        c = col - 1;
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r++;
            c--;
        }

        return true;
    }

    void placeQueen(int col, int n, vector<string> &board, vector<vector<string>> &ans) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {

            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                placeQueen(col + 1, n, board, ans);
                board[row][col] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        placeQueen(0, n, board, ans);
        return ans;
    }
};
