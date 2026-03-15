class Solution {
public:
    void sortColors(vector<int>& nums) {
        // ductch national flag algorithm
        int n = nums.size();

        int left = 0; // left side for 0s
        int right = n-1; // right side for 2s
        int mid = 0;

        while(mid <= right)
        {
            if(nums[mid] == 0)
            {
                swap(nums[left], nums[mid]);
                left++;
                mid++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[right]);
                right--;
            }
        }
        
        
    }
};