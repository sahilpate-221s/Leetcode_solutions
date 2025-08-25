class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>>umap;

        int n= mat.size();
        int m = mat[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j= 0;j<m;j++)
            {
                int sum = i+j;
                umap[sum].push_back(mat[i][j]);
            }
        }

        vector<int>answer;
        for(auto [i,vec]:umap)
        {
            if(i%2 == 0)
            {
                reverse(vec.begin(),vec.end());
            }

            for(auto it: vec)
            {
                answer.push_back(it);
            }
        }

        return answer;
        
    }
};