class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freqMap;

        for (const string& word : words) {
            freqMap[word]++;
        }

        // Min-heap based on (-freq, word)
        priority_queue<pair<int, string>> pq;

        for (const auto& [word, freq] : freqMap) {
            pq.push({-freq, word});
        }

        // Use another min-heap to keep only top k elements
        priority_queue<pair<int, string>> topK;
        while (!pq.empty()) {
            topK.push(pq.top());
            pq.pop();
            if (topK.size() > k) {
                topK.pop();  // remove least frequent (or lex higher if tie)
            }
        }

        vector<string> result;
        while (!topK.empty()) {
            result.push_back(topK.top().second);
            topK.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
