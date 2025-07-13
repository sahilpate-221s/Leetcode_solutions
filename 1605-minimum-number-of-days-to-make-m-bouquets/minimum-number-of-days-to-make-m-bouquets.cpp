class Solution {
public:

    int checkBloom(int mid, vector<int>& bloomDay, int k)
    {
        int bloomdays = 0;
        int continousDays = 0;

        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i] <= mid)
            {
                continousDays++;
            }
            else
            {
                continousDays=0;
            }


            if(continousDays == k)
            {
                bloomdays++;
                continousDays = 0;
            }
        }
        return bloomdays;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {


        int left = 0;
        int right = *max_element(begin(bloomDay), end(bloomDay));

        int days = -1;
        while(left <= right)
        {
            long long mid = (left + right)/2;

            if(checkBloom(mid, bloomDay, k) >= m)
            {
                days= mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return days;
        
    }
};