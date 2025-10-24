class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);

        string word;
        vector<string>answer;
        while(ss >> word)
        {
            answer.push_back(word);
        }

        reverse(answer.begin(),answer.end());

        string result; 

        for(int i=0;i<answer.size();i++)
        {
            result+=(answer[i]);
            if(i<answer.size()-1)
            {
                result+= " ";
            }
        }
        return result;
        
    }
};