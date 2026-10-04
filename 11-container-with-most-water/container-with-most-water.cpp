class Solution {
public:
    int maxArea(vector<int>& height) {

        int size = height.size();
        int left = 0;
        int right = size - 1;
        int maxLeft = height[0];
        int maxRight = height[right];
        int area = 0;
        while (left < right) {
            maxLeft = max(maxLeft, height[left]);
            maxRight = max(maxRight, height[right]);
            int height = min(maxLeft, maxRight);
            int width = right - left;
            area = max(area, height * width);
            if (maxLeft < maxRight) {
                left++;
            } else
                right--;
        }
        return area;
    }
};