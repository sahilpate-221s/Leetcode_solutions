class Solution {
public:
    vector<vector<string>> result;
    int N;

    // now for better time complexity by reducing the call of isVlaid by using
    // extra space

    unordered_set<int> columns;
    unordered_set<int> antiDiag;
    unordered_set<int> diag;

    // bool isValid(vector<string>& board, int row, int col) {

    //     // upper ke liye
    //     for (int i = row - 1; i >= 0; i--) {
    //         if (board[i][col] == 'Q')
    //             return false;
    //     }

    //     // upper left diagonal
    //     for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
    //         if (board[i][j] == 'Q')
    //             return false;
    //     }

    //     // for upper right diagonal
    //     for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
    //         if (board[i][j] == 'Q')
    //             return false;
    //     }

    //     return true;
    // }

    void solve(vector<string>& board, int row) {
        // base case
        if (row >= N) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < N; col++) {
            int diagonal_val = row - col;
            int antiDiag_val = row + col;

            if (columns.find(col) != columns.end() ||
                antiDiag.find(antiDiag_val) != antiDiag.end() ||
                diag.find(diagonal_val) != diag.end()) {
                continue;
            }

            columns.insert(col);
            antiDiag.insert(antiDiag_val);
            diag.insert(diagonal_val);
            board[row][col] = 'Q';

            solve(board,row+1);

            columns.erase(col);
            antiDiag.erase(antiDiag_val);
            diag.erase(diagonal_val);
            board[row][col] = '.';


        }
    }
    vector<vector<string>> solveNQueens(int n) {

        result.clear();
        N = n;

        vector<string> board(n, string(n, '.'));

        solve(board, 0);

        return result;
    }
};