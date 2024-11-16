class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>required;

        for(int i=0;i<capacity.size();i++)
        {
            int val = capacity[i]-rocks[i];
            required.push_back(val);
        }

        int count = 0;
        sort(begin(required),end(required));

        for(int i=0;i<required.size();i++)
        {
            if(additionalRocks && required[i] <= additionalRocks)
            {
                additionalRocks = additionalRocks-required[i];
                count++;
            }
            else 
                break;

        }
        return count;
        
    }
};