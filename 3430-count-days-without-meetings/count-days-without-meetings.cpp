class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int n = meetings.size();

        int freeDays = 0;
        int maxDay = meetings[0][1];
        if(meetings[0][0]  > 1)
        {
            freeDays+= (meetings[0][0]-1);
        }

        for(int i=1;i<n;i++)
            {
                if(meetings[i][0] > maxDay)
                {
                    freeDays += (meetings[i][0]-maxDay)-1;
                    maxDay = meetings[i][1];
                }
                else
                {
                    if(meetings[i][1] > maxDay)
                    {
                        maxDay=meetings[i][1];
                    }
                }
            }

        if(maxDay != days)
        {
            freeDays+= (days-maxDay);
        }
        return freeDays;
        
    }
};