class Solution {
public:
    using P = pair<int,int>;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<P, vector<P>, greater<P>>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }

        while(k--)
        {
            int val = pq.top().first;
            int i = pq.top().second;
            pq.pop();
            val = val* multiplier;
            pq.push({val,i});
        }
        vector<int> result(nums.size(),0);
        while(!pq.empty())
        {
           int val = pq.top().first;
           int i =pq.top().second;
           pq.pop();
           result[i]=val;
        }
        return result;
        
    }
};