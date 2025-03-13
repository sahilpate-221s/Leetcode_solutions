class Solution {
public:
    bool check(vector<int>& nums, vector<vector<int>>& queries, int limit) {
        vector<int> arr(nums.size()+1, 0);
        for(int i=0; i<limit; i++) {
            arr[queries[i][0]] -= queries[i][2];
            arr[queries[i][1]+1]+=queries[i][2];
            
        }
        int dec = 0;
        long long sum = 0;
        for(int i=0; i<nums.size(); i++) {
            dec += arr[i];
            if(nums[i]+dec>0) sum += nums[i];
        }
        return sum==0;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        long long sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum+=nums[i];
        }
        if(sum == 0) return 0;
        int n = nums.size();
        
        int l = 1, r = queries.size();
        int res = -1;

        while(l <= r) {
            int mid = (l+r)/2;
            if(check(nums, queries, mid)) {
                res = mid;
                r = mid-1;
                cout << "-->1 \n";
            } else {
                l = mid+1;
                cout << "-->2 \n";
            }
        }
        return res;
    }
};