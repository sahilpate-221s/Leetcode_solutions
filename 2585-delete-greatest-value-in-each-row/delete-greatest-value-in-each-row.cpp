class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int times = grid[0].size();
        int n = grid.size();
        int m  = grid[0].size();

        for (int i = 0; i < n; i++) {
            sort(grid[i].rbegin(), grid[i].rend());
        }

        int result = 0;
        int k=0;
        while(times>=1)
        {
            int maxi = 0;
            for(int i=0;i<n;i++)
            {
                int largest = grid[i][k];
                maxi = max(largest, maxi);
            }
            k++;
            result+=maxi;
            times--;
        }

        return result;
        
        
    }
};