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
    long long totalSum = 0;
    long long answer;
    int mod = 1e9+7;


    int dfs(TreeNode* root)
    {
        if(!root)return 0;
        int curr = dfs(root->left) + dfs(root->right) + root->val;
        answer = max(answer, (totalSum-curr) * curr);
        return curr;
    }

    int maxProduct(TreeNode* root) {
        
        totalSum = dfs(root);
        dfs(root);

        return answer % mod;

    }
};