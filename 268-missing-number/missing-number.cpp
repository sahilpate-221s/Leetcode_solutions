class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        int totalSum = n * (n+1) /2;
        int arraySum= accumulate(nums.begin(),nums.end(),0);

        int answer = totalSum - arraySum;
        return answer;
        
    }
};
