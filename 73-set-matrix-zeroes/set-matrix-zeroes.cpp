class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int>rowVec(row,1);
        vector<int>colVec(col,1);

        for(int r=0;r<row;r++)
        {
            for(int c = 0;c<col;c++)
            {
                if(matrix[r][c] == 0)
                {
                    rowVec[r] = 0;
                    colVec[c] = 0;
                }
            }
        }

        //now changing the values in place in the matrix

        for(int r=0;r<row;r++)
        {
            for(int c = 0;c<col;c++)
            {
                if(rowVec[r]==0 || colVec[c] == 0)
                {
                    matrix[r][c] = 0;
                }
            }
        }
        
    }
};