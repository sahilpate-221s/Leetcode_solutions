class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowRemainingSum = accumulate(begin(grid[0]),end(grid[0]),0LL);
        long long secondRowRemainingSum = 0;
        long long minimumSum = LONG_LONG_MAX;

        for(int i=0;i<grid[0].size();i++)
        {
            firstRowRemainingSum -= grid[0][i];
            long long bestofRobot2 = max(firstRowRemainingSum, secondRowRemainingSum);
            minimumSum = min(minimumSum, bestofRobot2);
            secondRowRemainingSum += grid[1][i];
        }
        return minimumSum;
        
    }
};