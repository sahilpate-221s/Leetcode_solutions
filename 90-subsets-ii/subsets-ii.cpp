class Solution {
public:
    vector<vector<int>>answer;

    void solve(vector<int>& nums, int idx, vector<int>temp)
    {
        
            answer.push_back(temp);

        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx && nums[i] == nums[i-1])continue;
            temp.push_back(nums[i]);
            solve(nums,i+1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<int>temp;
        int idx = 0;

        solve(nums, idx, temp);

        return answer;
        
    }
};