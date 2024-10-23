class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL)
        {
            return root;
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> levelSum;
        //step1 find sum of each level and store in a levelSum array
        while(!q.empty())
        {
            int currLevelSum = 0;
            int n = q.size();
            while(n--)
            {
                TreeNode* curr = q.front();
                q.pop();
                currLevelSum += curr->val;

                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }

            }
                levelSum.push_back(currLevelSum);
        }

        // update each node with cousing sum
        q.push(root);
        root->val = 0;//rott have no courisn
        int i = 1;
        while(!q.empty())
        {
            int n = q.size();

            while(n--)
            {
                TreeNode* curr = q.front();
                q.pop();
                //level sum of curr level - sibling sum
                int siblingSum = curr->left != NULL ? curr->left->val: 0;
                siblingSum += curr->right != NULL ? curr->right->val: 0;

                if(curr->left)
                {
                    curr->left->val = levelSum[i]-siblingSum;
                    q.push(curr->left);
                }

                if(curr->right)
                {
                    curr->right->val = levelSum[i]-siblingSum;
                    q.push(curr->right);
                }
            }
            i++;
        }
        return root;
        
    }
};