class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;

        // Iterate over each subarray of size k
        for(int i = 0; i <= nums.size() - k; i++) {
            bool isConsecutive = true;

            // Check if the subarray from i to i+k-1 is consecutive
            for(int j = i + 1; j < i + k; j++) {
                if(nums[j] != nums[j-1] + 1) {
                    isConsecutive = false;
                    break;
                }
            }

            // If consecutive, add the last element of the subarray to the answer
            if(isConsecutive) {
                ans.push_back(nums[i + k - 1]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
