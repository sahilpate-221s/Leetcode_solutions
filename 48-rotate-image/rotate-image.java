class Solution {
    public void rotate(int[][] matrix) {
        
        int n  = matrix.length;
        int m = matrix[0].length;

        // do the transpose of this matrix

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<m;j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }


        for(int i=0;i<n;i++)
        {
            int left = 0;
            int right = m-1;

            while(left < right)
            {
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;

                left++;
                right--;
            }
        }


        
    }
}