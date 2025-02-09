class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int k = 0; k <= 31; k++) {
            int temp = (1 << k);
            int onecount = 0;
            for (auto& num : nums) {
                if ((num & temp) == 0) {

                } else {
                    onecount++;
                }
            }
            if (onecount % 3 == 1) {
                result = (result | temp);
            }
        }
        return result;
    }
};