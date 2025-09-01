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
    int maxi = 0;
    int helper(TreeNode* root)
    {
         if(!root)return 0;

        int left = helper(root->left);
        int right = helper(root->right);

        maxi = max(left+right, maxi);
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
       
       if(!root)return 0;
       helper(root);
       return maxi;
        
    }
};