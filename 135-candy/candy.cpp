class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        

        vector<int> count(n,1);

        //left to right candy check
        for(int i=1;i<n;i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                count[i] = max(count[i], count[i-1]+1);
            }
        }

        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i] > ratings[i+1])
            {
                count[i] = max(count[i], count[i+1]+1);
            }
        }

        int result = 0;
        for(int i=0;i<n;i++)
        {
            result += count[i];
            
        }
        return result;

        
    }
};