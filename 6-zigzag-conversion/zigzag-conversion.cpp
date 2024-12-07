class Solution {
public:
    string convert(string s, int numRows) {
        
        int n = s.length();

        vector<string> nums(min(numRows,n));
        if(numRows >= n || numRows==1)return s;

        int currRow = 0;

        bool goingDown = false;

        for(auto c: s)
        {
            nums[currRow]+=c;
            if(currRow == 0 || currRow == numRows-1)
            {
                goingDown = !goingDown;
            }
            currRow += goingDown ? 1: -1;
        }
        string result;
        for(auto ch: nums)
        {
            result+=ch;
        }
        return result;
        
    }
};