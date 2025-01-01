class Solution {
public:
    int maxScore(string s) {
        int n = s.length();

        int count0 =0;
        int count1=0;
        for(auto &it:s)
        {
            if(it=='1')count1++;
        }

        int maxCount = INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0')
            {
                count0++;
            }
            else
            {
                count1--;
            }

            maxCount = max(maxCount, count0+count1);
        }
        return maxCount;
    }
};