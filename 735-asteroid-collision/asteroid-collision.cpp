class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        vector<int> ans;
        int i = 0;

        while (i < nums.size()) {
            bool exploded = false;
            if (nums[i] > 0) {
                st.push(nums[i]);
            } else {
                while (!st.empty() && st.top() > 0) {
                    if (st.top() == abs(nums[i])) {
                        st.pop();
                        exploded = true;
                        break;
                    } else if (st.top() < abs(nums[i])) {
                        st.pop();
                    } else {
                        exploded = true;
                        break;
                    }
                }
                if (!exploded) {
                    st.push(nums[i]);
                }
            }
            i++;
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};