class Solution {
public:
    string removeOuterParentheses(string s) {
        string answer;
        int count = 0;
        for(auto num:s)
        {
            if(num == '(')
            {
                if(count > 0)
                {
                    answer.push_back(num);
                }
                count++;
            }
            else
            {
                count--;
                if(count > 0)
                {
                    answer.push_back(num);
                }
            }

        }
        return answer;
        
    }
};