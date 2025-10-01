class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int currentSum = 0;


        for(int i=0;i<k;i++)
        {
            currentSum+= cardPoints[i];
        }   

        int maxi = currentSum;

        int j = n-1;
        for(int i=k-1;i>=0;i--)
        {
            currentSum-= cardPoints[i];
            currentSum+= cardPoints[j];
            j--;

            maxi = max(maxi, currentSum);
        }
        return maxi;


        
        
    }
};