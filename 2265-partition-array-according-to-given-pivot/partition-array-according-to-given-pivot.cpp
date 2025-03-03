class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>pivotLess;
        vector<int>pivotEqual;
        vector<int>pivotMore;

        for(auto &it:nums)
        {
            if(it<pivot)
            {
                pivotLess.push_back(it);
            }
            else if(it==pivot)
            {
                pivotEqual.push_back(it);
            }
            else
            {
                pivotMore.push_back(it);
            }
        }

        vector<int>answer;
        for(int i=0;i<pivotLess.size();i++)
        {
            answer.push_back(pivotLess[i]);
        }
        for(int i=0;i<pivotEqual.size();i++)
        {
            answer.push_back(pivotEqual[i]);
        }
        for(int i=0;i<pivotMore.size();i++)
        {
            answer.push_back(pivotMore[i]);
        }

        return answer;
    }
};