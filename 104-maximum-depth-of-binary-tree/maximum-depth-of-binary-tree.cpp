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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        queue<TreeNode*> pq;

        pq.push(root);

        int level = 0;
        while (!pq.empty()) {
            int n = pq.size();

            while (n--) {
                TreeNode* node = pq.front();
                pq.pop();

                if (node->left)
                    pq.push(node->left);
                if (node->right)
                    pq.push(node->right);
            }
            level++;
        }

        return level;
    }
};