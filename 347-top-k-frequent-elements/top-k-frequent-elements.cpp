class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        priority_queue<P, vector<P>, greater<P>> pq;

        for (auto it : nums) {
            umap[it]++;
        }

        for (auto [val, freq] : umap) {
            pq.push({freq, val});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> answer;

        while (!pq.empty()) {
            int val = pq.top().second;
            pq.pop();
            answer.push_back(val);
        }
        return answer;
    }
};