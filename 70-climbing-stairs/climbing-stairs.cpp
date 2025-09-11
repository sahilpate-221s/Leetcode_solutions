class Solution {
public:
    int solve(int n) {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;

        int one = solve(n - 1);
        int two = solve(n - 2);

        return one + two;
    }
    int climbStairs(int n) {
        // return solve(n);

        if (n == 0)
            return 1;
        if (n == 1)
            return 1;

        int prev1 = 1;
        int prev2 = 1;

        for (int i = 2; i <= n; i++) {
            int val = prev1 + prev2;
            prev2 = prev1;
            prev1 = val;
        }
        return prev1;
    }
};