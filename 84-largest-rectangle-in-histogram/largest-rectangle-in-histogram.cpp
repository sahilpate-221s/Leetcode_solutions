class Solution {
public:
    int largestRectangleArea(vector<int>& nums) 
    {
        int n = nums.size();
        stack<int> st;
        int answer = 0;

        for(int i = 0; i < n; i++)
        {
            // jab chhoti height milti hai, tab area nikal lo
            while(!st.empty() && nums[i] < nums[st.top()])
            {
                int maxIdx = st.top();
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;
                answer = max(answer, nums[maxIdx] * width);
            }

            st.push(i);
        }

        // bache hue bars ke liye
        while(!st.empty())
        {
            int maxIdx = st.top();
            st.pop();

            int width = st.empty() ? n : n - st.top() - 1;
            answer = max(answer, nums[maxIdx] * width);
        }

        return answer;
    }
};
