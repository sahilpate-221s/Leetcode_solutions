class Solution {
public:
    vector<vector<int>>answer;

    void helper(int num, int target, int idx, vector<int>temp)
    {
        //base case
        if(temp.size() == num)
        {
            if(target == 0)
            {
                answer.push_back(temp);
            }
            return;
        }
    
        for(int i=idx;i<=9;i++)
        {
            // if(i>target)break;

            if(i <= target)
            {
                temp.push_back(i);
                helper(num, target-i,i+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        helper(k,n,1,temp);
        return answer;
    }
};