class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();
        int answer = INT_MAX;

        int left = 0;
        int sum = 0;

        for(int right = 0;right < n;right++)
        {
            sum+= nums[right];
            while(sum >= target)
            {
                sum-= nums[left];
                answer = min(answer, right-left + 1);
                left++;
            }
        }
        return answer == INT_MAX ? 0: answer;
        
    }
};