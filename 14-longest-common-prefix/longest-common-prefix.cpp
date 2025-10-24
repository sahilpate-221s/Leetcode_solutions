class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0)return "";

        sort(strs.begin(),strs.end());

        int size1 = strs[0].size();
        int size2 = strs[n-1].size();

        int i=0;
        string answer = "";
        while(i < min(size1, size2))
        {
            if(strs[0][i] == strs[n-1][i])
            {
                answer+= strs[0][i];
            }
            else break;

            i++;
        }
        return answer;
        
    }
};