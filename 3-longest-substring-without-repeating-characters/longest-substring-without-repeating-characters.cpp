class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> umap;

        int left = 0;
        int answer = 0;

        for (int right = 0; right < n; right++) {
            char ch = s[right];

            while (umap.find(ch) != umap.end()) {
                umap.erase(s[left]);
                left++;
            }
            umap[ch]++;
            answer = max(answer, right-left + 1);
        }
        return answer;
    }
};