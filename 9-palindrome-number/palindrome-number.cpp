class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int digit = x;
        long long  temp = 0;

        while (x > 0) {
            int num = x % 10;
            temp = temp * 10 + num;

            x = x / 10;
        }

        return digit == temp;
    }
};