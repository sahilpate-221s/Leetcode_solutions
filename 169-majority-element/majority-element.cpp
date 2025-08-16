class Solution {
public:
    int countElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (auto num : nums) {
            if (count == 0) {
                candidate = num;
            }

            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
    int majorityElement(vector<int>& nums) { return countElement(nums); }
};