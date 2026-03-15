class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        unordered_map<char,int>umap;
        int maxLen = 0;
        int left = 0;
        for(int right = 0;right < n;right++)
        {
            char ch = s[right];
            while(umap.find(ch) != umap.end())
            {
                umap[s[left]]--;
                if(umap[s[left]] == 0)
                {
                    umap.erase(s[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right-left+1);
            umap[ch]++;
        }
        return maxLen;
    }
};