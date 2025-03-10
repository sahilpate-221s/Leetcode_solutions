class Solution {
public:
    bool hasDuplicate(string s1, string s2 )
    {
        int arr[26] = {0};
        
        for(char &ch : s1) {
            if(arr[ch-'a'] > 0)
                return true;
            arr[ch-'a']++;
        }
        
        for(char &ch : s2) {
            if(arr[ch-'a'] > 0)
                return true;
        }
        
        return false;
    }

    unordered_map<string, int> mp;
    int solve(int idx, vector<string>& arr, string temp, int n)
    {
        //base case
        if(idx >=n)
        {
            return temp.length();
        }
        if(mp.find(temp) != mp.end())
            return mp[temp];

        int include = 0;
        int exclude = 0;
        if(hasDuplicate(arr[idx],temp))
        {
            exclude = solve(idx+1,arr,temp,n);
        }
        else
        {
            exclude = solve(idx+1,arr,temp,n);
            temp+=arr[idx];
            include = solve(idx+1,arr,temp,n);
        }

        return mp[temp]= max(exclude,include);
    }
    int maxLength(vector<string>& arr) {
        
        int n = arr.size();
        mp.clear();
        string temp = "";
        return solve(0,arr,temp,n);
    }
};