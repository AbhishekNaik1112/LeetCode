class Solution {
public:
    // Function to check if it's safe to place a queen at board[r][c]
    bool check(vector<string>& board, int r, int c) {
        // same col
        for (int i = r; i >= 0; --i) {
            if (board[i][c] == 'Q') {
                return false;
            }
        }

        // upp l dia
        for (int i = r, j = c; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // upp r dia
        for (int i = r, j = c; i >= 0 && j < board.size(); --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // no queen ret 1
        return true;
    }
    void search(vector<string>& board, int r, int& ans) {
        // ans++ if all q
        if (r == board.size()) {
            ans++;
            return;
        }

        // place q in each col in curr row
        for (int i = 0; i < board.size(); ++i) {
            if (check(board, r, i)) {
                board[r][i] = 'Q';

                search(board, r + 1, ans);

                // Bktk mark
                board[r][i] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        if (n <= 0)
            return 0;
        int ans = 0;
        // board with .
        vector<string> board(n, string(n, '.'));

        search(board, 0, ans);

        return ans;
    }
};
