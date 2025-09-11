class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // prefix sum approach
        vector<int> leftMultipleSum(n, 1);
        vector<int> rightMultipleSum(n, 1);

        vector<int> answer(n);

        for (int i = 1; i < n; i++) {
            // left = left * nums[i-1];
            leftMultipleSum[i] = leftMultipleSum[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            rightMultipleSum[i] = rightMultipleSum[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            answer[i] = leftMultipleSum[i] * rightMultipleSum[i];
        }
        return answer;
    }
};