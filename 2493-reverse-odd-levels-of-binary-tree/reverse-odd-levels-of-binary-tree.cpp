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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int level = 0;

        while(!que.empty())
        {
            int n = que.size();
            vector<TreeNode*> levelNode;

            while(n--)
            {
                TreeNode* temp = que.front();
                que.pop();

                levelNode.push_back(temp);

                if(temp->left)
                {
                    que.push(temp->left);
                }
                if(temp->right )
                {
                    que.push(temp->right);
                }
            }

            if(level %2==1)
            {
                int i=0;
                int j = levelNode.size()-1;
                while(i<j)
                {
                    int tempVal = levelNode[i]->val;
                    levelNode[i]->val = levelNode[j]->val;
                    levelNode[j]->val = tempVal;

                    i++,j--;
                }
            }
            level++;
        }
        return root;
        
    }
};