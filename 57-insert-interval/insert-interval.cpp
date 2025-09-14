class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>>answer;

        int i=0;
        for(;i<intervals.size();i++)
        {
            //first case 
            if(newInterval[0] > intervals[i][1])
            {
                answer.push_back(intervals[i]);
            }
            else if(newInterval[1] < intervals[i][0])
            {
                break;
            }
            else
            {
                newInterval[0] = min(newInterval[0],intervals[i][0]);
                newInterval[1] = max(newInterval[1],intervals[i][1]);
            }
        }
        answer.push_back(newInterval);

        for(;i<intervals.size();i++)
        {
            answer.push_back(intervals[i]);
        }

        return answer;
        
    }
};