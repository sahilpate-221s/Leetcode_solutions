class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        if(n < 3)return false;
        for(int i=1;i<n-1;i++)
        {
            if(arr[i]%2 != 0 && arr[i-1]%2 != 0 && arr[i+1]%2 != 0)return true;
        }
        return false;
    }
};