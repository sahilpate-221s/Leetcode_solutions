class Solution {
public:
    long long coloredCells(int n) {
        long long count =1;
        int i=0;
        while(i<n)
        {
            count+= 4*i;
            i++;
        }   
        return count;
    }
};