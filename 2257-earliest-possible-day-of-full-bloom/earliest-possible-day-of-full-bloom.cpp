class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();

        vector<pair<int,int>> vec(n);  //{plantTime[i],growTime[i]};

        for(int i=0;i<n;i++)
        {
            vec[i] = {plantTime[i],growTime[i]};
        }

        //sort in descending order
        auto lambda = [](pair<int,int>&p1, pair<int,int> &p2)
        {
            return p1.second > p2.second;

        };
        
        sort(vec.begin(),vec.end(),lambda);
        int maxBloomDays = 0;
        int prevPlantDay = 0;


        for(int i=0;i<n;i++)
        {
            int currPlantTime = vec[i].first;
            int currGrowTime = vec[i].second;
            prevPlantDay +=currPlantTime;

            int currPlantBloomTime = prevPlantDay + currGrowTime;

            maxBloomDays = max(maxBloomDays, currPlantBloomTime);
        }
        return maxBloomDays;

        
    }
};