class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        vector<int> rowCountIndex(row,0);
        vector<int> colCountIndex(col,0);

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    rowCountIndex[i]++;
                    colCountIndex[j]++;
                }
            }
        }

        int count = 0;

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    if(rowCountIndex[i] > 1 || colCountIndex[j] > 1)
                    {
                        count++;
                    }
                }
            }
        }

        return count;
        
    }
};