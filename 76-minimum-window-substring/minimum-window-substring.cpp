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

        int mini = INT_MAX;
        int startIdx = 0;
        int j = 0;

        string str = "";

        for (int i = 0; i < n; i++) {

            umap[s[i]]--;
            if (umap[s[i]] >= 0) {
                remaining--;
            }

            while (remaining == 0) {

                if (i - j + 1 < mini) {
                    startIdx = j;
                    mini = i - j + 1;
                }

                umap[s[j]]++;
                if (umap[s[j]] > 0) {
                    remaining++;
                }

                j++;
            }
        }

        if (mini == INT_MAX)
            return "";
        str = s.substr(startIdx, mini);
        return str;
    }
};