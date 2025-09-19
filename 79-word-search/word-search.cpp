class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int i, int j,
               int idx) {
        int n = board.size();
        int m = board[0].size();
        if (idx == word.size())
            return true;

        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';
        bool found = solve(board, word, i + 1, j, idx + 1) ||
                     solve(board, word, i - 1, j, idx + 1) ||
                     solve(board, word, i, j + 1, idx + 1) ||
                     solve(board, word, i, j - 1, idx + 1);

        board[i][j] = temp;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(board, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};