class Solution {
public:
    bool rotateString(string s, string goal) {
        string str = s+s;
         if(s.length() != goal.length())return false;

        if(str.find(goal) == -1)return false;
        return true;
    }
};