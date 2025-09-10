class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int size = prices.size();
        int maxProfit  = 0;

        int minTillNow = prices[0];

        for(int i=1;i<size;i++)
        {
            minTillNow = min(minTillNow, prices[i]);

            int profit = prices[i]- minTillNow;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};