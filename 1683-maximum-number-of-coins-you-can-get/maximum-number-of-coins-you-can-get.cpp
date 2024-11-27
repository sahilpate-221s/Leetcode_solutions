class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());

        int my =0;
        int i=0;
        int j = piles.size()-2;

        while(i<j)
        {
            my+=piles[j];
            j-=2;
            i++;
        }
        return my;
        
    }
};