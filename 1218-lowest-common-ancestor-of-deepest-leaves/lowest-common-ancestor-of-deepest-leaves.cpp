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
    unordered_map<int,int>umap;
    int maxdepth = 0;
    void height(TreeNode* root,int h)
    {
        if(!root)return;

        umap[root->val] = h;
        maxdepth = max(maxdepth,h);

        height(root->left,h+1);
        height(root->right,h+1);
    }

    TreeNode* lcaFind(TreeNode* root, int maxDepth)
    {
        if(!root)return NULL;

        if(umap[root->val] == maxDepth)
        {
            return root;
        }

        TreeNode* left = lcaFind(root->left,maxDepth);
        TreeNode* right = lcaFind(root->right,maxDepth);

        if(left && right)return root;
        if(!left)return right;
        return left;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        height(root,0);

        return lcaFind(root,maxdepth);
    }
};