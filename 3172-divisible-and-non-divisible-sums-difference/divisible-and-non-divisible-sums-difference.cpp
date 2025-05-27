class Solution {
public:
    int differenceOfSums(int n, int m) {
        
        vector<int>num1;
        vector<int>num2;
        for(int i=0;i<=n;i++)
        {
            if(i%m != 0)
            {
                num1.push_back(i);
            }
            else 
            {
                num2.push_back(i);
            }
        }
        int sum1 = accumulate(begin(num1),end(num1),0);
        int sum2 = accumulate(begin(num2),end(num2),0);

        return sum1-sum2;
    }
};