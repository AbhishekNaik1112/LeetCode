class Solution {
public:
    bool check(vector<string>& board, int r, int c) { //check to see if you can place q
        for (int i = 0; i < r; ++i)
            if (board[i][c] == 'Q' ||// col
                (c - r + i >= 0 && board[i][c - r + i] == 'Q') ||   //upp l
                (c + r - i < board.size() && board[i][c + r - i] == 'Q')) //upp r
                return false;
        return true;
    }

    void search(vector<string>& board, int r, int& ans) {
        if (r == board.size()) { //if all q alr there ans++
            ans++;
            return;
        }

        for (int i = 0; i < board.size(); ++i) {
            if (check(board, r, i)) {
                board[r][i] = 'Q';//place q
                search(board, r + 1, ans);
                board[r][i] = '.'; //bktk and change it to . again
            }
        }
    }

    int totalNQueens(int n) {
        if (n <= 0)
            return 0;
        int ans = 0;
        vector<string> board(n, string(n, '.')); //make board with all .
        search(board, 0, ans);
        return ans;
    }
};
