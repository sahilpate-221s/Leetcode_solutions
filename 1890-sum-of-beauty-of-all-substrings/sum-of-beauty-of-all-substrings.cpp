class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int mini = INT_MAX;
                int maxi = INT_MIN;

                for (auto it : freq) {
                    if (it > 0) {
                        mini = min(mini, it);
                        maxi = max(maxi, it);
                    }
                }

                count += (maxi - mini);
            }
        }
        return count;
    }
};
