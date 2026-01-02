class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        set<int>st;
        for(auto it: nums)
        {
            if(st.find(it) != st.end())
            {
                return it;
            }
            st.insert(it);
        }
        return -1;
        
    }
};