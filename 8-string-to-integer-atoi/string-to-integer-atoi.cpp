class Solution {
public:
    int solve(int i, string& s, int sign, long long value) {
        // Base case: stop if out of bounds or not a digit
        if (i >= s.length() || !isdigit(s[i])) {
            return sign * value;
        }

        int d = s[i] - '0';

        // Check for overflow before multiplying
        if (value > (INT_MAX - d) / 10) {
            return sign == -1 ? INT_MIN : INT_MAX;
        }

        // Recurse with next index and updated value
        return solve(i + 1, s, sign, value * 10 + d);
    }

    int myAtoi(string s) {
        int n = s.length();
        int sign = 1;
        int i = 0;

        // Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // If only spaces
        if (i >= n) return 0;

        // Handle + / -
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Start recursion with value = 0
        return solve(i, s, sign, 0);
    }
};
