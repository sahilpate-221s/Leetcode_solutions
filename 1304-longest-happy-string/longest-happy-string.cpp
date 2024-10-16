class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int totalIteration = a+b+c;
        int curra =0,currb=0,currc=0;
        string ans = "";

        for(int i=0;i<totalIteration;i++)
        {
            //check for a 
            if((a >=b and a>=c and curra !=2) or (a>0 and (currb ==2 or currc==2)))
            {
                ans+='a';
                curra++;
                a--;
                currb=0;
                currc=0;
            }
            else if((b>=a and b>=c and currb !=2) or (b>0 and (curra==2 or currc==2)))
            {
                ans+='b';
                currb++;
                b--;
                curra = 0;
                currc = 0;
            }
            else if((c>=a and c>=b and currc !=2) or (c>0 and (curra==2 or currb==2)))
            {
                ans+='c';
                currc++;
                c--;
                curra=0;
                currb=0;
            }
        }
        return ans;
        
    }
};