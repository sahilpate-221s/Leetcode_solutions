class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();

        unordered_map<char, int> umap;

        for (auto it : s) {
            umap[it]++;
        }

        auto lambda =
            [](pair<char, int>& a, pair<char, int>& b) {
                return a.second < b.second;
            };
            priority_queue<pair<char, int>, vector<pair<char, int>>,
                             decltype(lambda)>
                pq(lambda);

        for (auto [ch, freq] : umap) {
            pq.push({ch, freq});
        }

        string str = "";
        while (!pq.empty()) {
            str.append(pq.top().second, pq.top().first);
            pq.pop();
        }
        return str;
    }
};