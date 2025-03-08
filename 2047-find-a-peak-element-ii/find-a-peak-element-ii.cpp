class Solution {
public:
    int findIndex(vector<vector<int>>& mat,int n, int m ,int col)
    {
        int maxIndex = -1;
        int maxValue = -1;
        for(int i=0;i<n;i++)
        {
            if(mat[i][col] > maxValue)
            {
                maxValue = mat[i][col];
                maxIndex=i;
            }
        }
        return maxIndex;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m-1;

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            int maxIndex = findIndex(mat,n,m,mid);

            int left = mid-1 >=0 ? mat[maxIndex][mid-1]:-1;
            int right = mid+1 <m ? mat[maxIndex][mid+1]:-1;

            if(mat[maxIndex][mid] > left && mat[maxIndex][mid] > right)
            {
                return {maxIndex,mid};
            }
            if(mat[maxIndex][mid] < left)
            {
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return {-1,-1};
        
    }
};