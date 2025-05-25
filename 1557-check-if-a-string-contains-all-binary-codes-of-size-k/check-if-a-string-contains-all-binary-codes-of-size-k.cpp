class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string>st;

        int n = s.length();
        for(int i=0;i<=n-k;i++)
        {
            string str = s.substr(i,k);
            st.insert(str);
        }

        int len = pow(2,k);
        if(st.size() >= len)return true;
        return false;
    }
};