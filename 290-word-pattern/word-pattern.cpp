class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> p;
        stringstream ss(s);
        string word;
        while(ss>>word)
        {
            p.push_back(word);
        }
        // cout<<p.size();


        if(p.size() != pattern.size())return false;
        unordered_map<char,string> umap;
        set<string>sett;

        for(int i=0;i<pattern.size();i++)
        {
            char ch = pattern[i];
            if(umap.find(ch) != umap.end())
            {
                if(umap[ch]!=p[i])
                {
                    return false;
                }
            }
            else
            {
                if(sett.find(p[i]) != sett.end())
                {
                    return false;
                }
            }
            umap[ch]=p[i];
            sett.insert(p[i]);
        }
        return true;
    
    }
};