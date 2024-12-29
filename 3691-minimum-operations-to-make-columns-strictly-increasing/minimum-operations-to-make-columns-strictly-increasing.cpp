class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        // Check for an empty grid
        if (grid.empty()) return 0;

        int row = grid.size();
        int col = grid[0].size();

        int count = 0;

        for (int j = 0; j < col; j++) {
            int prev = grid[0][j]; // Initialize prev with the first element of the row
            for (int i = 1; i < row; i++) {
                if (grid[i][j] <= prev) {
                    int val = prev - grid[i][j] + 1; // Calculate the increment needed
                    count += val;                     // Add increment to count
                    grid[i][j] += val;               // Increment the grid value
                }
                prev = grid[i][j]; // Update prev to current value
            }
        }

        return count; // Total operations needed
    }
};
