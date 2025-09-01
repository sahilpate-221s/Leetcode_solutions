class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        if(n==0)return "";

        int maxi = 1;
        int start = 0;


        auto lambda = [&](int left, int right)
        {
            // isme hum mid se left peche ja ke dekh rhe aur mid se rigth aaage jake 
            // isss liye i,i kiya means odd length ki string hai
            //i,i+1, me even length ki aur mid me do elements ho skte hai iss liye aisa kya
            while(left >= 0 && right < n && s[left] == s[right])
            {
                if(right-left+1 > maxi)
                {
                    start = left;
                    maxi = right-left+1;
                }
                left--;
                right++;  
            }
        };
        

        for(int i=0;i<n;i++)
        {
            lambda(i,i);
            lambda(i,i+1);
        }

        return s.substr(start,maxi);
    }
};