class Solution {
public:
    // set<vector<int>> st;
    vector<vector<int>> answer;

    void helper(vector<int>& nums, int target, int idx, vector<int>& temp) {
        // base case

        if (target == 0) {
            answer.push_back(temp);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            if (nums[i] > target)
                break;

            temp.push_back(nums[i]);
            helper(nums, target - nums[i], i + 1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        helper(candidates, target, 0, temp);

        // for (auto it : st) {
        //     answer.push_back(it);
        // }
        return answer;
    }
};