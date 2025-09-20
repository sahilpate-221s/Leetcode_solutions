/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return NULL;

        // if both p and q are less than root then lca found in left side
        if(p-> val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p,q);
        }

        // if both p and q are greater than root lca lies in right side
        if(p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p,q);
        }

        return root;
        
    }
};