class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>umap;
        for(auto it: arr)
        {
            int rem = (it % k + k ) % k; //for handling negative remainder
            umap[rem]++;
        }

        if(umap[0]%2 !=0)return false; // ye check karenge jab sare elemts ka remainder 0 aaye and ye dekhenge ki freq even hai ki nahi

        for(int rem = 1; rem <=k/2;rem++)
        {
            int countHalf = k-rem;
            if(umap[countHalf] != umap[rem])return false; // ye check karenge ki dono elements ki freq same hai ki nahi;
        }
        return true;

        
        
    }
};