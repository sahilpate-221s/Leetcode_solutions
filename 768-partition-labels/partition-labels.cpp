class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();

        unordered_map<char,int>umap;
        vector<int>answer;

        for(int i=0;i<n;i++)
        {
            umap[s[i]] = i;
        }

        int start = 0;
        int end = 0;

        for(int i=0;i<n;i++)
        {
            end = max(end, umap[s[i]]);
            if(i == end)
            {
                answer.push_back(end-start + 1);
                start = i + 1;
            }
        }
        return answer;

        
        
    }
};