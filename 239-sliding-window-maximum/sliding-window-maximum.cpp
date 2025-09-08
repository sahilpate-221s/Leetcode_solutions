class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        deque<int>dq;
        vector<int>answer;

        for(int i=0;i<n;i++)
        {
            if(!dq.empty() && dq.front() == i-k)
            {
                dq.pop_front();
            }

            // second case remove all the elem jo smaller hai current se
            while(!dq.empty() && nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }

            // current index ko push kar do
            dq.push_back(i);

            // jab window size mil jaye tab push kar do
            if(i>=k-1)
            {
                answer.push_back(nums[dq.front()]);
            }
        }
        return answer;
    }
};