class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }

        while(k--)
        {
            int val = pq.top();
            pq.pop();
            score+= val;
            val = ceil((double)val/3);
            pq.push(val);
        }
        return score;
    }
};