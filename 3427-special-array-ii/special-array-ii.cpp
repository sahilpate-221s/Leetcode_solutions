class Solution {
public:
   bool isSame(int a, int b) {
        // Check if both numbers have the same parity
        return (a % 2 == b % 2);
    }
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> Sum(n, 0);
        int count = 0;
        for (int i = 1; i < n; i++) {
            if (isSame(nums[i], nums[i - 1])) {
                count++;
            }

            Sum[i] = count;
        }

        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            int cumsum = Sum[end] - Sum[start];
            if (cumsum != 0) {
                ans.push_back(false);
            } else {
                ans.push_back(true);
            }
        }

        return ans;
    }
};