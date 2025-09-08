class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int remaining = t.length();

        if (remaining > n)
            return "";

        unordered_map<char, int> umap;

        for (auto it : t) {
            umap[it]++;
        }

        int startIdx = 0;
        int miniLen = INT_MAX;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (umap[s[i]] > 0) {
                remaining--;
            }

            while (remaining <= 0) {
                if (remaining == 0) {
                    if (i - j + 1 < miniLen) {
                        startIdx = j;
                        miniLen =  i - j + 1;
                    }
                }

                umap[s[j]]++;
                if (umap[s[j]] > 0)
                    remaining++;
                j++;
            }
            umap[s[i]]--;
        }

        if (miniLen == INT_MAX)
            return "";
        return s.substr(startIdx, miniLen);
    }
};