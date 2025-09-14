class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();
        sort(intervals.begin(),intervals.end());


        int count = 0;
        int endTime = intervals[0][1];

        for(int i=1;i<n;i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start < endTime)
            {
                endTime = min(endTime, end);
                count++;
            }
            else
            {
                endTime = end;
            }
        }
        return count;
        
    }
};