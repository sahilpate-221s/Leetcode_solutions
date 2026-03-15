class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        unordered_map<char, int> lastIndex;
        int maxLen = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            char ch = s[right];
            if (lastIndex.find(ch) != lastIndex.end() &&
                lastIndex[ch] >= left) {
                left = lastIndex[ch] + 1;
            }
            lastIndex[ch] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};