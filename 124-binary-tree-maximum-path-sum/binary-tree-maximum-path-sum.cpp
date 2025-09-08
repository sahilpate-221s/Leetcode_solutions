class Solution {
public:
    int maxi = INT_MIN;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        int val = root->val;

        int one = max(left, right) + val;
        int second = left + right + val;

        maxi = max({maxi, val, one, second}); // fixed missing semicolon

        return max(val, one);
    }
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        dfs(root);
        return maxi;
    }
};
