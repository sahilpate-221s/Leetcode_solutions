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
    int idx = 0;
    TreeNode* solve(vector<int>& preorder, int lower, int upper)
    {
        if(idx == preorder.size())return NULL;

        int val = preorder[idx];

        if(val < lower || val > upper)return NULL;
        idx++;

        TreeNode* root = new TreeNode(val);

        root->left = solve(preorder, lower,val-1);
        root->right = solve(preorder, val+1, upper);


        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder, INT_MIN,INT_MAX);
        
    }
};