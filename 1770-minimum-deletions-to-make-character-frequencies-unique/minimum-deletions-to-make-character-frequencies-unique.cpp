class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(char &ch: s)
        {
            freq[ch-'a']++;
        }
        
        // unordered_set<int> st;
        // int result = 0;
        
        // for(int i=0;i<26;i++)
        // {
        //     while(freq[i] > 0 && st.find(freq[i]) != st.end())
        //     {
        //         result++;
        //         freq[i]--;
        //     }

        //     st.insert(freq[i]);
        // }
        // return result;
        int result = 0;
        sort(begin(freq),end(freq));
        for(int i=24;i>=0;i--)
        {
            if(freq[i] >= freq[i+1])
            {
                int prev = freq[i];
                freq[i] = max(0,freq[i+1]-1);
                

                result+=prev-freq[i];
            }
        }
        return result;
        
    }
};