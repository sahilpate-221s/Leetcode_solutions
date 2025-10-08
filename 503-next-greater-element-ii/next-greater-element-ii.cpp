class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        vector<int>answer(n,-1);
        stack<int>st;

        for(int i=0;i<2*n;i++)
        {
            while(!st.empty() && nums[i % n] > nums[st.top() % n])
            {
                answer[st.top() % n] = nums[i%n];
                st.pop();
            }

            if(i<n)st.push(i);
        }
        return answer;
        
    }
};