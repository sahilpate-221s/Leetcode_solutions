class Solution {
public:
    int t[10001];
    int helper(int n )
    {
        //base case 
        if(n<=0)return 0;
        if(t[n] != -1)return t[n];

        int minCount = INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            int result = 1+ helper(n-(i*i));
            minCount = min(minCount, result);
        }
        return t[n] =  minCount;
    }
    int numSquares(int n) {
        memset(t,-1,sizeof(t));
        return helper(n);
    }
};