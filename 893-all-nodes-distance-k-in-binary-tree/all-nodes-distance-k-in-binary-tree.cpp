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
    unordered_map<TreeNode* , TreeNode*>parent;

    void inorder(TreeNode* root)
    {
        if(!root)return;

        if(root->left )
        {
            parent[root->left] = root;
        }
        inorder(root->left);
        if(root->right)
        {
            parent[root->right] = root;
        }
        inorder(root->right);
    }

    void BFS(TreeNode* target, int k , vector<int>& result)
    {
        queue<TreeNode*> pq;
        pq.push(target);

        unordered_set<int> visited;
        visited.insert(target->val);

        while(!pq.empty())
        {
            int n = pq.size();
            if(k==0)break;

            while(n--)
            {
                TreeNode* curr = pq.front();
                pq.pop();
                
                //left
                if(curr->left != NULL && !visited.count(curr->left->val))
                {
                    pq.push(curr->left);
                    visited.insert(curr->left->val);
                }

                //right
                if(curr->right != NULL && !visited.count(curr->right->val))
                {
                    pq.push(curr->right);
                    visited.insert(curr->right->val);
                }
                //parent

                if(parent.count(curr) && !visited.count(parent[curr]->val))
                {
                    pq.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }

        while(!pq.empty())
        {
            TreeNode* temp = pq.front();
            pq.pop();
            result.push_back(temp->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>result;
        inorder(root);

        BFS(target,k , result);
        return result;
        
    }
};