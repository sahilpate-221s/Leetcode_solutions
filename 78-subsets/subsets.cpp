class Solution {
public:
    vector<vector<int>> answer;

    void helper(vector<int>& nums, int i, vector<int> temp) {
        if (i == nums.size()) {
            answer.push_back(temp);
            return;
        }

        // exclude

        helper(nums, i + 1, temp);
        temp.push_back(nums[i]);
        // include
        helper(nums, i + 1, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> temp;
        helper(nums, 0, temp);
        return answer;
    }
};