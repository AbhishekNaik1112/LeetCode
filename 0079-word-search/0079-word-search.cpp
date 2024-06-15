class Solution {
public:
    bool searchChar(vector<vector<char>>& board, string word, int i, int j,
                    int row, int col, int pointer) {
        // base cases
        if (pointer >=
            word.size()) // checking if the pointerr has reached end of word
            return true;

        if (i < 0 || i >= row || j < 0 || j >= col ||
            board[i][j] == '.' || // boundaries and necc conditions
            board[i][j] != word[pointer])
            return false;

        char temp = board[i][j]; // placeholder
        board[i][j] = '.';

        bool found =
            searchChar(board, word, i, j - 1, row, col, pointer + 1) || // L
        searchChar(board, word, i, j + 1, row, col, pointer + 1) ||   // R
        searchChar(board, word, i - 1, j, row, col, pointer + 1) ||    // U
        searchChar(board, word, i + 1, j, row, col, pointer + 1);     // D

        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // setting up row and col
        int row = board.size();
        int col = board[0].size();

        // if no row or no word
        if (row == 0 || word.size() == 0)
            return false;
        // traverse the board
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    if (searchChar(board, word, i, j, row, col, 0))
                        return true; // board matrix,given word,position i j
                                     // ,row,col and word pointer
                }
            }
        }
        return false;
    }
};