class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rowLen = mat.size();
        int colLen = mat[0].size();

        unordered_map<int,pair<int,int>>umap;
        for(int i=0;i<rowLen;i++)
        {
            for(int j=0;j<colLen;j++)
            {
                int val = mat[i][j];
                umap[val]= {i,j};
            }
        }

        map<int,int> rowCount;
        map<int,int> colCount;

        for(int i=0;i<arr.size();i++)
        {
            pair<int,int> val = umap[arr[i]];
            int r = val.first;
            int c = val.second;
            rowCount[r]++;
            colCount[c]++;

            if(rowCount[r]==colLen || colCount[c]==rowLen)
            {
                return i;
            }
        }
        return -1;
        
    }
};