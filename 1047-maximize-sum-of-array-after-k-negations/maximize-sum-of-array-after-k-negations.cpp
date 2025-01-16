class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto &it:nums)
        {
            pq.push(it);
        }

        while(k--)
        {
            int val = pq.top();
            pq.pop();
            val = -val;
            pq.push(val);
        }
        int sum = 0;
        while(!pq.empty())
        {
            sum+=pq.top();
            pq.pop();
        }
        return sum;
        
    }
};