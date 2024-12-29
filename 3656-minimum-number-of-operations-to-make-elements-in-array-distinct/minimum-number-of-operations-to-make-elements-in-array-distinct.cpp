class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> freq(101,0);
        int n = nums.size();

        for(int i=n-1;i>=0;i--)
        {
            freq[nums[i]]++;
            if(freq[nums[i]] > 1)
            {
                return ceil((double)(i+1)/3);
            }

        }
        return 0;
        
    }
};
