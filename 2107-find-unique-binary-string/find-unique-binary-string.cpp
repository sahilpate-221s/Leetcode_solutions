class Solution {
public:
    string result;
    bool found = false;
    void solve(string& str, unordered_set<string>&st,int index)
    {
        //base case
        if(found)return;
        if(st.find(str) == st.end())
        {
            st.insert(str);
            result = str;
            found=true;
            return;
        }

        for(int i=index;i<str.length();i++)
        {
            str[i] = (str[i] == '0') ? '1' : '0';
            solve(str,st,index+1);
            str[i] = (str[i] == '0') ? '1' : '0';
        }
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>st;
        for(auto &it:nums)
        {
            st.insert(it);
        }

        string str(nums[0].size(), '0');
        solve(str,st,0);
        return result;
        
    }
};