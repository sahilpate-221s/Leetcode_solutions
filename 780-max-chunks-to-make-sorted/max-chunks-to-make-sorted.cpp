class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int currSum = 0;
        int Osum = 0;
        int count = 0;
        for(int i=0;i<arr.size();i++)
        {
            currSum += arr[i];
            Osum += i;
            if(currSum == Osum)count++;
        }

        return count;
        
    }
};