class Solution {
public:
    int n;
    unordered_set<string>st;
    void solve(string & tiles, string& result,vector<bool>& used)
    {
        st.insert(result);

        for(int i=0;i<n;i++)
        {
            if(used[i]==true)continue;
            //do
            used[i]=true;
            result+=tiles[i];

            //explore
            solve(tiles,result,used);

            //undo
            used[i] = false;
            result.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        n = tiles.size();
        vector<bool>used(n,false);
        string result = "";
        solve(tiles,result,used);

        //empty set bhi store ho jayega iss liye -1 karenge
        return st.size()-1;
        
    }
};