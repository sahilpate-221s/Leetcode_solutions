class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int maxFreq = 0;
        int maxi = 0;
        int j = 0;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'A']++;
            maxFreq = max(maxFreq, freq[s[i] - 'A']);

            // If the current window size minus the count of the most frequent
            // character is greater than k, shrink the window
            // isme jo (i-j+1) hai ye windowsize hai  windowsize-maxFreq agar k se badi hai to 
            //out of bound 
            if ((i - j + 1) - maxFreq > k) {
                freq[s[j] - 'A']--;
                j++; // Shrink the window
            }

            maxi = max(maxi, i - j + 1); // Update max length
        }

        return maxi;
    }
};