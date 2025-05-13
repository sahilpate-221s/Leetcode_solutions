class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {


        int Tcount = 0;
        int Fcount = 0;
        int left= 0;
        int right = 0;
        int maxi = 0;

        int n = answerKey.length();

        while(right < n)
        {
            
            if(answerKey[right] == 'T')Tcount++;
            else Fcount++;

            while(min(Tcount,Fcount) > k)
            {
                if(answerKey[left]=='T')Tcount--;
                else 
                    Fcount--;

                    left++;
            }

            maxi = max(maxi, (right-left+1));

            right++;

        }
        return maxi;
        
    }
};