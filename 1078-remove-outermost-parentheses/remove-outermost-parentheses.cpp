class Solution {
public:
    string removeOuterParentheses(string s) {
        string answer;
        int count = 0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                if(count > 0)
                {
                    answer+=s[i];
                }
                count++;
            }
            else
            {
                count--;
                if(count > 0)
                {
                    answer+=s[i];
                }
            }
        }
        return answer;
        
    }
};