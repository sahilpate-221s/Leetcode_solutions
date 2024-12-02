class Solution {
public:
    int n;
    bool isPred(string& curr, string& prev) {
        int i = 0;             // prev ke liye
        int j = 0;             // cirr ke liye
        int N = curr.length(); // prev ke liye
        int M = prev.length();
        if (M + 1 != N) return false;

        while (i < M && j < N) {
            if (prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return (i==M);
    }

    int LIS(int index, vector<string>& words, int prev,vector<vector<int>>& dp) {
        if (index == n)
            return 0;

        int take = 0, noTake = 0;
        if(dp[index][prev+1] != -1)return dp[index][prev+1];

        if (prev == -1 || isPred(words[index], words[prev])) {
            take = 1 + LIS(index + 1, words, index,dp);
        }
        noTake = LIS(index + 1, words, prev,dp);

        return dp[index][prev+1]= max(take, noTake);
    }

    static bool myFunction(string& a, string& b) { return a.length() < b.length(); }

    int longestStrChain(vector<string>& words) {
        n = words.size();

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        sort(begin(words), end(words), myFunction);

        return LIS(0, words, -1, dp);
    }
};