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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root)
            return {};

        vector<vector<int>> answer;
        map<int, vector<int>> umap;

        queue<pair<TreeNode*, int>> pq;
        pq.push({root, 0});


        while (!pq.empty()) {
            int n = pq.size();
            map<int, vector<int>> levelMap;

            while (n--) {
                TreeNode* node = pq.front().first;
                int level = pq.front().second;
                pq.pop();


                levelMap[level].push_back(node->val);

                if (node->left)
                    pq.push({node->left, level - 1});
                if (node->right)
                    pq.push({node->right, level + 1});
            }

            for(auto &it:levelMap)
            {
                sort(it.second.begin(),it.second.end());

                for(auto v: it.second)
                {
                    umap[it.first].push_back(v);
                }
            }
        }

        for (auto [val, vec] : umap) {
            answer.push_back(vec);
        }
        return answer;
    }
};