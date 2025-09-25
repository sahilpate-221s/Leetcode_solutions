class Solution {
public:
    string solve(string& nums, int k) {
        while (k--) {
            int n = nums.length();

            int i = n - 1;

            for (; i > 0; i--) {
                if (nums[i - 1] < nums[i])
                    break;
            }

            int index = i;
            if (i != 0) {
                for (int j = n - 1; j >= 1; j--) {
                    if (nums[j] > nums[i - 1]) {
                        index = j;
                        break;
                    }
                }
                swap(nums[index], nums[i - 1]);
            }

            reverse(nums.begin() + i, nums.end());
        }

        return nums;
    }
    string getPermutation(int n, int k) {
        string num = "";
        for (int i = 0; i < n; i++) {
            num += to_string(i + 1);
        }

        k=k-1;
        return solve(num, k);
    }
};