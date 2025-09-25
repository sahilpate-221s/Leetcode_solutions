class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        vector<int>freq(26,0);
        int left = 0;
        int result =0;
        int maxFreqCount = 0;

        for(int right=0;right<n;right++)
        {
            freq[s[right]-'A']++;

            maxFreqCount = max(maxFreqCount, freq[s[right]-'A']);


            while((right-left+1) - maxFreqCount > k)
            {
                freq[s[left]-'A']--;
                left++;
            }

            result = max(result, right-left+1);
        }
        return result;
        
    }
};