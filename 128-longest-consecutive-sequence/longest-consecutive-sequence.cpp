class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n  = nums.size();

        set<int>st;
        for(auto it:nums)
        {
            st.insert(it);
        }

        int maxi = 0;

        for(int x:st)
        {
            if(!st.count(x-1))
            {
                int current = x;
                int length = 1;

                while(st.find(current+1) != st.end())
                {
                    current = current+1;
                    length++;
                }
                maxi = max(maxi, length);
            }
        }
        return maxi;

        
    }
};