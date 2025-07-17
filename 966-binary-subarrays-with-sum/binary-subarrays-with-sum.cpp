class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n= nums.size();
        int count = 0; // count the total number of subarrays 

        int sum = 0; // finds the running sum of the array till i
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++)
        {


            sum += nums[i];

            // check if sum == goal
            if(sum == goal)count++;

            // finding the remaing sum which might found previously 
            int rem = sum-goal;
            if(umap.find(rem) != umap.end())
            {
                count+= umap[rem];
            }
            umap[sum]++;
        }
        return count;
    }
};