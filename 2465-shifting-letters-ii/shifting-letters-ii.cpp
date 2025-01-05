class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();

        vector<int> suffixSum(n, 0);

        for (auto& vec : shifts) {
            int start = vec[0];
            int end = vec[1];
            int x = vec[2];

            if (x == 1) {
                suffixSum[start]+= 1;
                if (end + 1 < n) {
                    suffixSum[end+1] -= 1;
                }

            } else {
                suffixSum[start]--;
                if (end + 1 < n) {
                    suffixSum[end + 1]++;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            suffixSum[i] = suffixSum[i - 1] + suffixSum[i];
        }

        for (int i = 0; i < n; i++) {
            int shift = suffixSum[i] % 26;
            if (shift < 0) {
                shift += 26;
            }
            s[i] = ((s[i] - 'a' + shift) % 26) + 'a';
            /*
                Note : s[i]-'a' gives the corresponding number of character s[i]
                       +shift adds the shift
                       %26 is to wrap around (0-25)
                       'a' + in the end converts back the number to character
            */
        }

        return s;
    }
};