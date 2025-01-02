class Solution {
public:
    unordered_set<char> umap = {'a', 'e', 'i', 'o', 'u'};

    bool check(const string& word) {
        int len = word.length();
        if (len == 0)
            return false; // Handle empty string case

        char first = word[0];
        char last = word[len - 1]; // Fixing the out-of-bounds access

        // Check if both first and last characters are in the set
        if (umap.find(first) != umap.end() && umap.find(last) != umap.end()) {
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> result;

        vector<int> prefixSum(n + 1, 0);

        prefixSum[0] = 0;
        for (int i = 1; i <= n; i++) {
            prefixSum[i] =
                prefixSum[i - 1] +(check(words[i - 1]) ? 1 : 0);
        }
        // cout<< words[0].length()<<endl;

        // return prefixSum;

        // now iterate through queries and find the len
        for (auto& vec : queries) {
            int start = vec[0];
            int end = vec[1];

            int val = prefixSum[end + 1] - prefixSum[start];
            result.push_back(val);
        }

        return result;
    }
};