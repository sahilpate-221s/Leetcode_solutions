class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int arraySum = accumulate(nums.begin(), nums.end(),0);
        int nSum = n * (n + 1) /2;

        int missing = nSum - arraySum;
        return missing;
    }
};