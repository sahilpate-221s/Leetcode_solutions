class Solution {
public:
    bool winnerOfGame(string colors) {
        int n =  colors.size();
        int alice = 0;
        int bob = 0;
        for(int i=1;i<n-1;i++)
        {
            if(colors[i] == colors[i-1] && colors[i]==colors[i+1])
            {
                (colors[i]=='A')? alice++ : bob++;
            }
        }
        if(alice <=bob)return false;
        return true;
        
    }
};