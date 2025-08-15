class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        for(int r=0;r<row;r++)
        {
            for(int c=r+1;c<col;c++)
            {
                swap(matrix[r][c], matrix[c][r]);
            }
        }

        for(int i=0;i<row;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};