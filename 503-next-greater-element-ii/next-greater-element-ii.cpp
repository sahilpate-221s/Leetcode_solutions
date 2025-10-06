class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        stack<int>st;
        vector<int>answer(n,-1);

        for(int i=0;i<2*n;i++)
        {
            while(!st.empty() && nums[st.top() % n] < nums[i%n])
            {
                answer[st.top() % n] = nums[i%n];
                st.pop();
            }
            if(i<n) st.push(i);
        }

        return answer;
        
    }
};