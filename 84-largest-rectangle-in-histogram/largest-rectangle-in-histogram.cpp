class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        int i = 0;

        while (i < n) {
            // If stack is empty or current bar is taller/equal, push its index
            if (st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i++);
            } else {
                // Found a bar shorter than the one at stack top
                int topIdx = st.top();
                st.pop();

                // Determine width
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, heights[topIdx] * width);
            }
        }

        // Process any bars still in the stack
        while (!st.empty()) {
            int topIdx = st.top();
            st.pop();
            int width = st.empty() ? i : (i - st.top() - 1);
            maxArea = max(maxArea, heights[topIdx] * width);
        }

        return maxArea;
    }
};
