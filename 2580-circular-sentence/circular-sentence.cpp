class Solution {
public:
    bool isCircularSentence(string sentence) {
        
        vector<string> result;
        stringstream ss(sentence);
        string ch="";
        while(ss>>ch)
        {
            result.push_back(ch);
        }
        //checking for first and las 
        char first = result[0][0];
        string lastWord = result[result.size() - 1]  ;
        char last = lastWord[lastWord.length() - 1];

        if(first != last)
            return false;

        char  lastOne = first;
        for(string st:result)
        {
            if(st[0]!= lastOne)
            {
                return false;
            }
            lastOne = st[st.length()-1];

        }
        return true;
    }
};