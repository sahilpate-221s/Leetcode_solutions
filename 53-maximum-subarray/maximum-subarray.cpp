class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefixSum(n, 0);
        vector<int> miniArray(n, 0);

        prefixSum[0] = nums[0];
        miniArray[0] = 0;
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];

            miniArray[i] = min(miniArray[i - 1], prefixSum[i - 1]);
        }

        int answer = nums[0]; 

        for (int i = 0; i < n; i++) {
            answer = max(answer, prefixSum[i] - miniArray[i]);
        }
        return answer;
    }
};