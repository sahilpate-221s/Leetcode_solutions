class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;

            int n = nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i] < nums[i-1])count++;
        }
        if(nums[n-1] > nums[0])count++; // it makes sures that the rotation doesnt affect the sorting

        return count <= 1 ? true:false;
        
    }
};