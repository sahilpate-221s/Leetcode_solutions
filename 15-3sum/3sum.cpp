class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());

        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;

            // int sum = nums[i];
            while (j < k && j < n && k < n) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    st.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }

                if (sum < 0) {

                    j++;
                }
                if (sum > 0) {

                    k--;
                }
            }
        }

        for (auto vec : st) {
            answer.push_back(vec);
        }

        return answer;
    }
};