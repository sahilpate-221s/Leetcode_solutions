class Solution {
public:
    int beautySum(string s) {
        int count = 0;

        int n = s.length();

        for(int i=0;i<n;i++)
        {

            int arr[26] = {0};
            for(int j=i;j<n;j++)
            {
                arr[s[j]-'a']++;
                int mini = INT_MAX;
                int maxi = INT_MIN;

                for(auto it: arr)
                {
                    if(it > 0)
                    {
                        maxi = max(maxi, it);
                        mini = min(mini, it);
                    }
                }
                count+= maxi-mini;
            }
        }
        return count;
        
    }
};