/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int InStart,
                    int InEnd, int PStart, int PEnd) {
        // base case
        if (InStart > InEnd)
            return NULL;

        TreeNode* root = new TreeNode(postorder[PEnd]);
        int rootvalue = root->val;

        int i = InStart;
        for (; i <= InEnd; i++) {
            if (inorder[i] == rootvalue)
                break;
        }

        int leftsize = i - InStart;
        int rightsize = InEnd - i;

        root->left = solve(inorder, postorder, InStart, i - 1, PStart,
                           PStart + leftsize - 1);
        root->right =
            solve(inorder, postorder, i + 1, InEnd, PEnd - rightsize, PEnd - 1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        int InStart = 0;
        int InEnd = n - 1;

        int PStart = 0;
        int PEnd = n-1;

        return solve(inorder, postorder, InStart, InEnd, PStart, PEnd);
    }
};