class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalElement = n * n;

        int totalsum = totalElement * (totalElement + 1) / 2;
        int missing = 0;
        int duplicate = 0;

        unordered_set<int> st;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            for (auto& it : grid[i]) {
                if (st.find(it) != st.end()) {
                    duplicate = it;
                }
                sum += it;
                st.insert(it);
            }
        }
        sum -= duplicate;
        missing = totalsum - sum;
        return {duplicate, missing};
    }
};