class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int maxArea = 0;

        int left = 0;
        int right = n - 1;

        while (left < right) {
            int width = min(nums[left], nums[right]);

            int area = (right - left) * width;
            maxArea = max(maxArea, area);

            if (nums[left] < nums[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};