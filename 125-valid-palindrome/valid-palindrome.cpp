class Solution {
public:
    bool helper(int i, int j, string& str)
    {
        //base case
        if(i>j)return true;
        
        if(str[i] == str[j])
        {
            return helper(i+1,j-1,str);
        }
        return false;
    }
    bool isPalindrome(string s) {
        
        string str = "";

        for(int i=0;i<s.length();i++)
        {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i]<='9'))
            {
                str+= tolower(s[i]);
            }

        }

        int j = str.length()-1;
        return helper(0,j,str);
    }
};