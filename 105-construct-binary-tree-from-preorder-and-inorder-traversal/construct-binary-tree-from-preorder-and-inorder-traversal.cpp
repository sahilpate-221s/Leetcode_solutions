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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& idx, int start, int end)
    {
        // base case
        if(start > end)return NULL;

        int rootValue = preorder[idx];
        int i = start;
        for(;i<=end;i++)
        {
            if(inorder[i] == rootValue)break;
        }
        // idx ko increase karenge
        idx++;

        TreeNode* root = new TreeNode(rootValue);
        root->left = solve(preorder, inorder, idx, start, i-1);
        root->right = solve(preorder, inorder, idx, i+1, end);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int  n = preorder.size();

        int idx = 0;
        return solve(preorder, inorder, idx, 0, n-1);
        
    }
};