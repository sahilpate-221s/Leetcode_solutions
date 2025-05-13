class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>answer;

        for(int i=0;i<nums.size();i++)
        {
            //first case check for window size
            if(!dq.empty() && dq.front() == i-k)
            {
                dq.pop_front();
            }

            //second case remove all the elemtns which are smaller that the current
            while(!dq.empty() && nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }

            // third case
            dq.push_back(i);

            // forth case if we get widow size push max element
            if(i>=k-1)
            {
                answer.push_back(nums[dq.front()]);
            }
            
        }
        return answer;
        
    }
};