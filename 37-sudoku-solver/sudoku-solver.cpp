class Solution {
public:
    bool solved = false;

    bool isValid(vector<vector<char>>& board, int row, int col, char digit)
    {
        // horizontal check
        for(int i=0;i<9;i++)
        {
            if(board[row][i] == digit)return false;
        }
        // vertical check

        for(int i=0;i<9;i++)
        {
            if(board[i][col] == digit)return false;
        }
        // checking the whole 3x3 box is the digit present in the box twice;
        int sr = (row /3 ) * 3;
        int sc = (col/3 ) * 3;  // how this works let say col = 5 -> 5/3 = 1 * 3 = 3

        for(int i=sr;i<=sr+2;i++)
        {
            for(int j=sc;j<=sc+2;j++)
            {
                if(board[i][j] == digit)return false;
            }
        }



        return true;
    }

    void solve(vector<vector<char>>& board, int row, int col) {
        // base case
        if (row == 9) {
            solved = true;
            return;
        }

        // find next row and col
        int nrow = row;
        int ncol = col + 1;
        if (ncol == 9) {
            ncol = 0;
            nrow = nrow + 1;
        }

        // main logic
        if (board[row][col] != '.') // if its not empty space run for next call
        {
            solve(board, nrow, ncol);
        } else // if its empty loop from 1 to 9
        {
            for (char i = '1'; i <= '9'; i++) {
                if (isValid(board, row, col, i)) {
                    board[row][col] = i;
                    solve(board, nrow, ncol);
                    if (solved)
                        return;

                    board[row][col] = '.';
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
        
    }
};