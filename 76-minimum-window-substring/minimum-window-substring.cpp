class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int remaining = t.length();
        if (remaining > n)
            return "";

        unordered_map<char, int> umap;
        int maxLen = INT_MAX;
        for (auto it : t) {
            umap[it]++;
        }

        int left = 0;
        int start = 0;

        int i = 0;
        for (; i < n; i++) {
            char ch = s[i];
            umap[ch]--;
            if (umap[ch] >= 0) {
                remaining--;
            }

            while (remaining == 0) {
                if (i - left + 1 < maxLen) {
                    maxLen = i - left + 1;
                    start = left;
                }
                umap[s[left]]++;
                if (umap[s[left]] > 0)
                    remaining++;

                left++;
            }
        }
        if (maxLen == INT_MAX)
            return "";
        return s.substr(start, maxLen);
    }
};