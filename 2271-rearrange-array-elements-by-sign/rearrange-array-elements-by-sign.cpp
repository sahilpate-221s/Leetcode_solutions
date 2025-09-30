class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        int posIdx = 0;
        int negIdx = 1;
        vector<int> answer(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                if (posIdx < n) {
                    answer[posIdx] = nums[i];
                    posIdx += 2;
                }
            } else {
                if (negIdx < n) {
                    answer[negIdx] = nums[i];
                    negIdx += 2;
                }
            }
        }

        return answer;
    }
};