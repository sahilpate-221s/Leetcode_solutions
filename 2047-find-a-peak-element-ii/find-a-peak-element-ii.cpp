class Solution {
public:
//row based approach 
    int findMaxIndex(vector<vector<int>>& mat, int m, int row) {
        int maxIndex = -1;
        int maxValue = -1;

        for (int j = 0; j < m; j++) {
            if (mat[row][j] > maxValue) {
                maxValue = mat[row][j];
                maxIndex = j;
            }
        }
        return maxIndex;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            // Find the column index of the maximum element in the mid row
            int maxIndex = findMaxIndex(mat, m, mid);

            // Get up and down neighbors
            int up = mid - 1 >= 0 ? mat[mid - 1][maxIndex] : -1;
            int down = mid + 1 < n ? mat[mid + 1][maxIndex] : -1;

            if (mat[mid][maxIndex] > up && mat[mid][maxIndex] > down) {
                return {mid, maxIndex};
            }

            // Move towards the bigger neighbor (up or down)
            if (mat[mid][maxIndex] < down) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return {-1, -1};
    }
};
