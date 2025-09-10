class Solution {
public:
    vector<vector<string>> result;

    unordered_set<int> columns;
    unordered_set<int> diagonals;
    unordered_set<int> antiDiagonals;

    void solve(vector<string>& board, int row, int n) {
        // base case
        if (row >= n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            // find the diagonal and antidiagoal
            int anti_diagonal = row - col;
            int diagonal = row + col;
            // if we find that the queen has aleready placed in the path all
            // paths columns, diagonals, and antiDiagonals

            if (columns.find(col) != columns.end() ||
                diagonals.find(diagonal) != diagonals.end() ||
                antiDiagonals.find(anti_diagonal) != antiDiagonals.end()) {
                continue;
            }

            columns.insert(col);
            diagonals.insert(diagonal);
            antiDiagonals.insert(anti_diagonal);
            board[row][col] = 'Q';

            solve(board, row + 1, n);

            columns.erase(col);
            diagonals.erase(diagonal);
            antiDiagonals.erase(anti_diagonal);
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        solve(board, 0,n);

        return result;
    }
};