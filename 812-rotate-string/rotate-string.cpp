class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())return false;
        string add = s+s;
        if(add.find(goal) ==-1)
        {
            return false;
        }
        return true;
        
    }
};