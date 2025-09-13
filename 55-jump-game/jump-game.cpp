class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int index = nums[0];

        for(int i=0;i<nums.size();i++)
        {
            
            if(index >= nums.size()-1)return true;
            if(index == i && nums[i] == 0)return false;

            if(i + nums[i] > index) index = i+nums[i];
        }
        return true;
    }
};