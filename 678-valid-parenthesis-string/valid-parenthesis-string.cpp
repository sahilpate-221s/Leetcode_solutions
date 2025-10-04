class Solution {
public:
    bool checkValidString(string s) {
        stack<int>bracket, aestrik;
        int n  = s.length();

        for(int i=0;i<n;i++)
        {
            char ch = s[i];

            if(ch == '(')
            {
                bracket.push(i);
            }
            else if (ch == '*')
            {
                aestrik.push(i);
            }
            else
            {
                if(!bracket.empty())
                {
                    bracket.pop();
                }
                else if(!aestrik.empty())
                {
                    aestrik.pop();
                }
                else return false;
            }
        }

        while(!bracket.empty() && !aestrik.empty())
        {
            if(bracket.top() > aestrik.top())return false;
            else
                bracket.pop();
                aestrik.pop();
        }

        return bracket.empty();
        
    }
};