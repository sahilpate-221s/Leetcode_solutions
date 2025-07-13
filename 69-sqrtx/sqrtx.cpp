class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)return x;
        int left = 0;
        int right = x;

        int ans = 0;
        while(left <= right)
        {
            long long mid =  (left + right)/2;

            long long  val = mid * mid;
            if(val == x)return mid;
            if(val < x)
            {
                ans = mid;
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
            
        }
        return ans;
        
    }
};