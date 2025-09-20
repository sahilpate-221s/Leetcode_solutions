class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>umap;

        vector<vector<string>>answer;


        for(int i=0;i<strs.size();i++)
        {
            string str = strs[i];
            sort(begin(str), end(str));
            umap[str].push_back(strs[i]);
        }

        for(auto [it, vec]:umap)
        {
            answer.push_back(vec);
        }

        return answer;
        
    }
};