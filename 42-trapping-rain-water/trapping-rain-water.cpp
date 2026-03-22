class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();

        int leftMax = 0;
        int rightMax = 0;

        int left = 0;
        int right = size-1;

        int answer = 0;
        while(left < right)
        {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            if(leftMax <= rightMax)
            {
                answer+= leftMax - height[left];
                left++;
            }
            else
            {
                answer+= rightMax - height[right];
                right--;
            }
        }
        return answer;
        
    }
};