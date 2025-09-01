class Solution {
public:
    int helper(string& s, int i,int result,int sign)
    {
        if(i>=s.length() || !isdigit(s[i]))return result;

        int digit = s[i]-'0';

        //overflow handle karna 
        if(result > (INT_MAX - digit)/10)
        {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        result  = result * 10 + digit;
        return helper(s,i+1,result,sign);
    }
    int myAtoi(string s) {
        int n = s.length();

        int sign = 1;

        int i=0;
        
        //checking for whiespaces
        while(i<n && s[i]==' ')
        {
            i++;
        }

        // now checking for sign 
        if(s[i] == '-' || s[i]=='+')
        {
            if(s[i]=='-') sign = -1;
            i++;
        }

        int result = helper(s, i,0,sign);

        if(sign == -1 && result == INT_MIN)return INT_MIN;
        if(sign == -1 )return -result;

        return result;
        


        
    }
};