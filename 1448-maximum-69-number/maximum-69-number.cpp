class Solution {
public:
    int maximum69Number(int num) {
        int placeValofSix = -1;
        int placeVal = 0;
        int temp = num;
        while(temp)
        {
            int rem = temp%10;
            if(rem == 6)
            {
                placeValofSix  = placeVal;
            } 
            temp = temp/10;
            placeVal++;
        }
        int ans = num;
        if(placeValofSix >=0)
        {
            ans = num+ (3*pow(10,placeValofSix));
        }
        return ans;
    }
};