class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int count = 0;
        priority_queue<long long,vector<long long>,greater<long long >>pq;
        for(auto &it:nums)
        {
            pq.push(it);
        }
        // cout<<pq.top()<<"first element"<<endl;

        while(pq.size() > 1 && pq.top()<k)
        {
            long long  a = pq.top();
            pq.pop();
            long long  b = pq.top();
            pq.pop();

            long long  val = (1LL * min(a,b) * 2) + max(a,b);
            count++;
            pq.push(val);
        }
        return count;
        
    }
};