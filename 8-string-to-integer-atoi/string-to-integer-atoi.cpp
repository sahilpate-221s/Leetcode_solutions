class Solution {
public:
    int solve(int i, string& s, int sign) {
        long long digit = 0;

        while (i < s.length() && isdigit(s[i])) {
            int d = s[i] - '0';

            if (digit > (INT_MAX - d) / 10) {
                return sign == -1 ? INT_MIN : INT_MAX;
            }

            digit = digit * 10 + d;
            i++;
        }

        return sign * digit;
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

        // Parse digits
        return solve(i, s, sign);
    }
};
