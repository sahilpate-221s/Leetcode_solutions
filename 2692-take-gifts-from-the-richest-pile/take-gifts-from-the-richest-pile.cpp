class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long result = 0;

        priority_queue<int> pq(begin(gifts),end(gifts));

        while(k--)
        {
            int val = pq.top();
            pq.pop();
            val = floor(sqrt(val));
            pq.push(val);
        }

        while(!pq.empty())
        {
            result+=pq.top();
            pq.pop();
        }
        return result;
        
    }
};