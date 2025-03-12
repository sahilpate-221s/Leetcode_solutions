class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>umap;

        for(auto &it:nums)
        {
            umap[it]++;
        }

        priority_queue<pair<int,int>>pq;
        for(auto &[val,freq] : umap)
        {
            pq.push({freq,val});
        }

        vector<int>answer;
        while(k--)
        {
            answer.push_back(pq.top().second);
            pq.pop();
        }

        return answer;
    }
};