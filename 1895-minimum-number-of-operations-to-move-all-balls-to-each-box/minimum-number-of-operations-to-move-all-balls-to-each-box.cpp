class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();

       vector<int> answer(n,0);

       int cumVal = 0;
       int cumvalueSum = 0;

       for(int i=0;i<n;i++)
       {
        answer[i]= cumvalueSum;
        cumVal += boxes[i]=='0'?0:1;
        cumvalueSum+= cumVal;
       }

       cumVal = 0;
       cumvalueSum = 0;

       for(int i=n-1;i>=0;i--)
       {
        answer[i]+= cumvalueSum;
        cumVal += boxes[i]=='0'?0:1;

        cumvalueSum += cumVal;
       }

       return answer;
        
    }
};