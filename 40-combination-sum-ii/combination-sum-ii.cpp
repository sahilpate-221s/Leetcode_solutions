class Solution {
public:
    vector<vector<int>>answer;

    void solve(vector<int>& nums, int idx, vector<int>temp, int target)
    {
        if(target == 0)
        {
            answer.push_back(temp);
            return;
        }

        for(int i=idx;i<nums.size();i++)
        {
            if(i> idx && nums[i]==nums[i-1])continue;
            if(nums[i] > target)break;
            temp.push_back(nums[i]);

            solve(nums, i+1,temp,target-nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {


        vector<int>temp;
        sort(begin(candidates),end(candidates));

        solve(candidates,0,temp,target);
        return answer;
        
    }
};