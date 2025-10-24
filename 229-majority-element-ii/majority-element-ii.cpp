class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int count1 = 0, count2 = 0;
        int candidate1 = INT_MIN, candidate2 = INT_MAX;

        vector<int> answer;

        for (int i = 0; i < n; i++) {
            // ✅ move equality checks to the top (to avoid duplicate candidates)
            if (nums[i] == candidate1) {
                count1++;
            } else if (nums[i] == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // checking
        int f1 = 0, f2 = 0;

        for (auto num : nums) {
            if (num == candidate1)
                f1++;
            else if (num == candidate2)
                f2++;
        }

        if (f1 > n / 3)
            answer.push_back(candidate1);
        if (f2 > n / 3)
            answer.push_back(candidate2);

        return answer;
    }
};
