class Solution {
public:
    int lengthOfLongestSubstring(string nums) {
        int n = nums.length();

        int j = 0;
        unordered_map<char, int> umap;
        int maxLength = 0;
        for (int i = 0; i < n; i++) {

            char ch = nums[i];

            while (umap.find(ch) != umap.end()) {
                umap[nums[j]]--;
                if (umap[nums[j]] == 0)
                    umap.erase(nums[j]);
                
                j++;
            }

            maxLength = max(maxLength, i - j + 1);
            umap[ch]++;
        }

        return maxLength;
    }
};