class Solution {
public:
    string compressedString(string word) {
        string result = "";
        int count = 0,i=0,j=0;
        while(j<word.length())
        {
            count = 0;
            while(j< word.length() && word[i]==word[j] && count < 9)
            {
                j++;
                count++;
            }
            result+=to_string(count)+word[i];
            i=j;
        }
        return result;
        
    }
};