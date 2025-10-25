class Solution {
public:
    int solve(int idx, string& s, int sign) {
        int answer = 0;
        while (idx < s.length() && isdigit(s[idx])) {
            int digit = s[idx] - '0';
            if (answer > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            answer = answer * 10 + digit;
            idx++;
        }

        return answer * sign;
    }
    int myAtoi(string s) {
        int n = s.length();

        int i = 0;
        int sign = 1;
        // removing the spaces
        while (i < n && s[i] == ' ')
            i++;

        if (i < n && s[i] == '-' || s[i] == '+') {
            sign = (s[i]=='-') ? -1: 1;
            i++;    
        }

        int result = solve(i, s, sign);
        return result;
    }
};