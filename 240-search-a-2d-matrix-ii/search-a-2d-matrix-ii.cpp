class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n= matrix.size();
        int m = matrix[0].size();

        int left = 0;
        int right = m-1;
    

        while(left < n &&  right >= 0)
        {
            int element = matrix[left][right];

            if(element == target)return true;

            if(element < target)
            {
                left++;
            }
            else    right--;
        }
        return 0;
        
    }
};