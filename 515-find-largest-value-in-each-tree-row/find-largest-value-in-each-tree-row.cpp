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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> que;
        que.push(root);
        vector<int> result;
        while(!que.empty()) 
        {
            int n = que.size();
            vector<int> temp;
            while(n--)
            {
                TreeNode* value = que.front();
                que.pop();
                temp.push_back(value->val);
                if(value->left)
                {
                    que.push(value->left);
                }
                if(value->right)
                {
                    que.push(value->right);
                }
            }
            int maxi = *max_element(temp.begin(), temp.end());
            result.push_back(maxi);
        }
        return result;
    }
};