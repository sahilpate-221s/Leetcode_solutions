/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* r1, TreeNode* r2)
    {
        //base case
        if(!r1)return r2;
        if(!r2)return r1;

        TreeNode* root = new TreeNode(r1->val + r2->val);
        root->left = solve(r1->left,r2->left);
        root->right = solve(r1->right,r2->right);


        return root;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        return solve(root1,root2);
    }
};