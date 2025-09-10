class Solution {
public:
    int helper(string s, int i, int result , int sign )
    {
        if(i>=s.length() || !isdigit(s[i]))
        {
            return result;
        }

        int digit = s[i]-'0';

        // overflow se bachne ke liye 
        if(result > (INT_MAX - digit)/10)
        {
            return sign == 1 ? INT_MAX: INT_MIN;
        }
        result  = result * 10 + digit;
        return helper(s, i+1,result, sign);
    }
    int myAtoi(string s) {
        
        int n = s.length();
        int i = 0;
        int sign = 1;

        //step1 removing the leading whitespaces
        while(i<n)
        {
            if(s[i] == ' ')
            {
                i++;
            }
            else break;
        }

        // steps 2 : checking for negative signs 
        if(s[i] == '-' || s[i] == '+')
        {
            if(s[i] == '-')sign = -1;
            i++;
        }

        // step 3 converting the remainign valid string to the number;
        int result = helper(s, i, 0, sign);

        // if number is negative and not valid so return the MIN value possible
        if(sign==-1 && result == INT_MIN)return INT_MIN;
        // if number is negative and is valid then we return the negative number
        if(sign == -1)return -result;
        // else return the original number which we get
        return result;

    }
};