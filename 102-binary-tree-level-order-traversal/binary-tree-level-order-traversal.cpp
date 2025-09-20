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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};

        queue<TreeNode*> pq;
        pq.push(root);


        vector<vector<int>> answer;

        while (!pq.empty()) {
            int n = pq.size();
            vector<int> temp;
            while (n--) {
                TreeNode* node = pq.front();
                pq.pop();
                temp.push_back(node->val);

                if (node->left) {
                    pq.push(node->left);
                }

                if (node->right) {
                    pq.push(node->right);
                }
            }

            answer.push_back(temp);


        }

        return answer;
    }
};