class Solution {
public:
    bool can_place(int i, int j, char value, vector<vector<char>>& board) {
        int n = board.size();
        // same row
        for (int col = 0; col < n; col++) {
            if (board[i][col] == value) {
                return false;
            }
        }
        // same column
        for (int row = 0; row < n; row++) {
            if (board[row][j] == value) {
                return false;
            }
        }
        // same 3x3 box
        int sr = (i / 3) * 3;
        int sc = (j / 3) * 3;

        for (int row = sr; row < sr + 3; row++) {
            for (int col = sc; col < sc + 3; col++) {
                if (board[row][col] == value) {
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(int i, int j, vector<vector<char>>& board) {
        int n = board.size();
        // All rows completed
        if (i == n) {
            return true;
        }
        // Move to next row
        if (j == n) {
            return solve(i + 1, 0, board);
        }

        // Already filled position
        if (board[i][j] != '.') {
            return solve(i, j + 1, board);
        }

        // Try 1 to 9
        for (char val = '1'; val <= '9'; val++) {
            if (can_place(i, j, val, board)) {
                board[i][j] = val;
                if (solve(i, j + 1, board)) {
                    return true;
                }
                // Backtrack
                board[i][j] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
         solve(0, 0, board);
        }
};