class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans;
        for (int i = 0; i < n - 1; i++) {
            int j = i + 1;
            while (j < n && prices[j] > prices[i]) {
                j++;
            }
            if (j < n) {

                int val = prices[i] - prices[j];
                ans.push_back(val);
            } else {
                ans.push_back(prices[i]);
            }
        }
        ans.push_back(prices[n - 1]);

        return ans;
    }
};