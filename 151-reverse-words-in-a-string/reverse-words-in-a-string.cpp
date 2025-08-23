class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;

        vector<string>nums;

        while(ss>>word)
        {
            nums.push_back(word);
        }

        string answer = "";

        for(int i=nums.size()-1;i>=0;i--)
        {
            answer+=(nums[i]);
            if(i>0)
            {
                answer+= " ";
            }
        }
        return answer;
        
    }
};