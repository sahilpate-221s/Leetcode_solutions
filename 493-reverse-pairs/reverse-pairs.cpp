class Solution {
private:
    long long merge(vector<int>& nums, int start, int mid, int end) {

        int j = mid + 1;
        vector<int> temp;

        long long count = 0;

        // counting reverse pairs
        for (int i = start; i <= mid; i++) {
            while (j <= end && (long long)nums[i] > 2LL * nums[j])
                j++;

            count += (j - (mid + 1)); // this we are counting all pair from i,
                                      // form mid+2 till j
        }

        int i = start;
        j = mid + 1;

        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid)
            temp.push_back(nums[i++]);
        while (j <= end)
            temp.push_back(nums[j++]);

        for (int i = 0; i < temp.size(); i++) {
            nums[start + i] = temp[i];
        }

        return count;
    }
    int mergesort(vector<int>& nums, int start, int end) {
        if (start >= end)
            return 0;

        int mid = (start + end) / 2;

        int left = mergesort(nums, left, mid);
        int right = mergesort(nums, mid + 1, end);

        int mergeLeftandRight = merge(nums, start, mid, end);
        return mergeLeftandRight + left + right;
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        int pairs = mergesort(nums, 0, n - 1);
        return pairs;
    }
};