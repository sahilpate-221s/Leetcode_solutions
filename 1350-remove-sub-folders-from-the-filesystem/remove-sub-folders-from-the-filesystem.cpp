class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string>umap(begin(folder),end(folder));
        vector<string> result;
        for(string currFolder : folder)
        {
            bool isSubFolder = false;
            string tempFolder = currFolder;
            while(!currFolder.empty())
            {
                size_t position = currFolder.find_last_of('/');
                currFolder = currFolder.substr(0,position);

                if(umap.find(currFolder) != umap.end())
                {
                    isSubFolder = true;
                    break;
                }
            }
            if(!isSubFolder)
            {
                result.push_back(tempFolder);
            }
        }

        return result;
        

        
    }
};