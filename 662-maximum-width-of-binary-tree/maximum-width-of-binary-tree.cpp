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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;

        ll maxi = 0;
                // node, distance
        queue<pair<TreeNode*, ll>>pq;
        pq.push({root,0});

        while(!pq.empty())
        {
            int n= pq.size();
            int leftMost = pq.front().second;
            int rightMost = pq.back().second;
            maxi = max((int)maxi,(rightMost-leftMost+1));

            while(n--)
            {
                TreeNode* node = pq.front().first;
                ll side = pq.front().second;
                pq.pop();

                if(node->left)
                {
                    pq.push({node->left, 2* side + 1});
                }
                if(node->right)
                {
                    pq.push({node->right, 2* side+2});
                }

            }

            
        }
        return maxi;
        
    }
};