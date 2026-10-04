class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int maxLeft = height[0];
        int maxRight = height[n - 1];

        int left = 0;
        int right = n - 1;
        int count = 0;

        while (left < right) {
            maxLeft = max(maxLeft, height[left]);
            maxRight = max(maxRight, height[right]);

            if (maxLeft <= maxRight) {
                count += maxLeft - height[left];
                left++;
            } else {
                count += maxRight - height[right];
                right--;
            }
        }
        return count;
    }
};