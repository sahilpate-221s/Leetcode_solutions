class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        int curr = 0;
        int far = 0;

        for(int i=0;i<n-1;i++)
        {
            far = max(i + nums[i], far);

            if(i == curr)
            {
                count++;
                curr = far;
            }

        }
        return count;
    }
};