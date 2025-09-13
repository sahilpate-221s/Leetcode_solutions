class Solution {
public:
    vector<vector<int>> answer;

    void solve(int idx, vector<int>& nums, int target, vector<int> temp) {
        if (idx == nums.size()) {
            if (target == 0) {
                answer.push_back(temp);
            }
            return;
        }
        solve(idx + 1, nums, target, temp);

        if (nums[idx] <= target) {
            temp.push_back(nums[idx]);
            solve(idx, nums, target - nums[idx], temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();

        vector<int> temp;

        solve(0, candidates, target, temp);
        return answer;
    }
};