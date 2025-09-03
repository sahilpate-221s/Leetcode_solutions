class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                // ✅ Visit immediately (Preorder)
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* leftchild = curr->left;

                // ✅ find predecessor correctly
                while (leftchild->right != NULL && leftchild->right != curr) {
                    leftchild = leftchild->right;
                }

                if (leftchild->right == NULL) {
                    // ✅ First time visit
                    result.push_back(curr->val);
                    leftchild->right = curr;
                    curr = curr->left;
                } else {
                    // ✅ Remove thread
                    leftchild->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return result;
    }
};
