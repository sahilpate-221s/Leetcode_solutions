class Solution {
public:
    int helper(string& s, int i, int result, int sign) {
        // Base case: stop if out of bounds or not a digit
        if (i >= s.length() || !isdigit(s[i])) {
            return result;
        }

        int digit = s[i] - '0';

        // Overflow handling before updating `result`
        if (result > (INT_MAX - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;

        return helper(s, i + 1, result, sign);
    }

    int myAtoi(string s) {
        int n = s.length();
        int i = 0;

        // Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i == n) return 0; // If the entire string is empty or just spaces

        // Checking for sign
        int sign = 1;
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // Recursively construct the integer
        int result = helper(s, i, 0, sign);

        // **Fix Overflow Issue Before Returning**
        if (sign == -1 && result == INT_MIN) return INT_MIN;  // Directly return INT_MIN
        if (sign == -1) return -result;  // Convert only if within bounds
        return result;
    }
};
