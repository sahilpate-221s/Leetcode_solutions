class Solution {
public:
    vector<vector<int>> answer;

    void solve(vector<int>& nums, int idx, int target, vector<int> temp) {
        if (idx == nums.size()) {
            if (target == 0) {
                answer.push_back(temp);
            }
            return;
        }

        // take
        if (nums[idx] <= target) {
            temp.push_back(nums[idx]);
            solve(nums, idx, target - nums[idx], temp);
            temp.pop_back();
        }

        // noTake
        solve(nums, idx + 1, target, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        int idx = 0;

        solve(candidates, idx, target, temp);
        return answer;
    }
};