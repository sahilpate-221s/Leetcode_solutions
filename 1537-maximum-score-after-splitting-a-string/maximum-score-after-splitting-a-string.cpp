class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> zero_prefix(n+1,0);
        vector<int> one_suffix(n+1,0);


        int maxCount = INT_MIN;
        //prefix sum for zero count
        for(int i=1;i<=n;i++)
        {
            zero_prefix[i] = zero_prefix[i-1]+ (s[i-1]=='0'?1:0);
        }

        //suffix sum for one count 
        for(int i=n-1;i>=0;i--)
        {
            one_suffix[i] = one_suffix[i+1] + (s[i]=='1'?1:0);
        }

        // now traverse from left to rigth ans add the zero and one 
        for(int i=1;i<n;i++)
        {
            maxCount  = max(maxCount, one_suffix[i]+zero_prefix[i]);
        }
        return maxCount;


        
    }
};