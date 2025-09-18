/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        if (root == NULL)
            return str;

        queue<TreeNode*> pq;
        pq.push(root);

        while (!pq.empty()) {
            TreeNode* node = pq.front();
            pq.pop();

            if (node == NULL) {
                str += "#";
                str += ",";
            } else {
                str += to_string(node->val);
                str += ',';

                pq.push(node->left);
                pq.push(node->right);
            }
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data.length() == 0)return {};

        stringstream ss(data);
        string str;

        getline(ss,str,',');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode* >pq;
        pq.push(root);

        while(!pq.empty())
        {
            TreeNode* node = pq.front();
            pq.pop();

            getline(ss, str, ',');
            if(str != "#")
            {
                node->left = new TreeNode(stoi(str));
                pq.push(node->left);
            }
            getline(ss,str, ',');
            if(str != "#")
            {
                node->right = new TreeNode(stoi(str));
                pq.push(node->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));