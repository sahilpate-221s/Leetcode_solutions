class Solution {
    public int maxProfit(int[] prices) {

        int last = prices[0];
        int profit = 0;
        int n = prices.length;

        for(int i=1;i<n;i++)
        {
            last = Math.min(last, prices[i]);
            profit = Math.max(prices[i] - last,profit);
        }
        return profit;
        
    }
}