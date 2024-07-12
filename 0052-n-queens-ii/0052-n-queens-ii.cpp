class Solution {
public:
    // Function to check if it's safe to place a queen at board[r][c]
    bool check(vector<string>& board, int r, int c) {
        // Check the same column upwards
        for (int i = r; i >= 0; --i) {
            if (board[i][c] == 'Q') {
                return false;
            }
        }

        // Check the upper left diagonal
        for (int i = r, j = c; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check the upper right diagonal
        for (int i = r, j = c; i >= 0 && j < board.size(); --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // If no queens are attacking, it's safe to place the queen
        return true;
    }

    // Recursive function to solve the N-Queens problem
    void rec(vector<string>& board, int r, int& ans) {
        // If all queens are placed, increment the solution count
        if (r == board.size()) {
            ans++;
            return;
        }

        // Try placing a queen in each column of the current row
        for (int i = 0; i < board.size(); ++i) {
            if (check(board, r, i)) {
                // Place the queen
                board[r][i] = 'Q';

                // Recur to place the rest of the queens
                rec(board, r + 1, ans);

                // Backtrack and remove the queen
                board[r][i] = '.';
            }
        }
    }

    // Main function to return the number of distinct N-Queens solutions
    int totalNQueens(int n) {
        if (n <= 0)
            return 0;

        // Initialize the solution count to zero
        int ans = 0;

        // Initialize the board with empty spaces ('.')
        vector<string> board(n, string(n, '.'));

        // Start the recursive solving process from the first row
        rec(board, 0, ans);

        // Return the total number of solutions found
        return ans;
    }
};
