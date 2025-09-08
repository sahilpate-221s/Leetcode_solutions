class Solution {
public:
    struct Info {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    int maxsum = 0;

    Info dfs(TreeNode* root) {
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN}; // empty subtree is BST
        }

        Info left = dfs(root->left);
        Info right = dfs(root->right);

        // Check if current node forms a BST with left & right subtrees
        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            int currSum = root->val + left.sum + right.sum;
            maxsum = max(maxsum, currSum);
            return {true, currSum, min(root->val, left.minVal), max(root->val, right.maxVal)};
        }

        // Not a BST
        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        maxsum = 0;
        dfs(root);
        return maxsum;
    }
};
