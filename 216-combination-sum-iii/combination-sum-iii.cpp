class Solution {
public:
    vector<vector<int>> st;
    void helper(int i, int target, int n, vector<int>& temp) {
        // base case
        if (temp.size() == n) {
            if (target == 0) st.push_back(temp);
            return;
        }

        for (int start = i; start <= 9; start++) {
            if (start > target)
                break;

            temp.push_back(start);
            helper(start + 1, target - start, n, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> temp;
        helper(1, n, k, temp);

        
        
        return st;
    }
};