class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> umap;
        int count = 0;

        for (auto& d : dominoes) {
            // Encode the domino such that (a,b) and (b,a) map to the same key
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            int key = a * 10 + b;  // Since 1 <= domino[i][j] <= 9, this works

            count += umap[key]; // Add the number of existing identical dominoes
            umap[key]++;
        }

        return count;
    }
};