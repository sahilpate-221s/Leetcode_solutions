class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string str = "";

        for (auto x : s) {
            if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') ||
                (x >= '0' && x <= '9')) {
                str += tolower(x);
            }
        }

        if (str.empty())
            return true;

        int i = 0;
        int j = str.length() - 1;

        while (i < j) {
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};