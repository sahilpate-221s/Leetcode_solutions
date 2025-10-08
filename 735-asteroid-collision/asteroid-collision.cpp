class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {

        int n = nums.size();
        stack<int> st;
        vector<int> answer;


        for (int i = 0; i < n; i++) {
            bool blast = false;
            if (nums[i] > 0)
                st.push(nums[i]);
            else {
                while (!st.empty() && st.top() > 0) {
                    if (st.top() == abs(nums[i])) {
                        st.pop();
                        blast = true;
                        break;
                    } else if (st.top() < abs(nums[i])) {
                        st.pop();
                    } else {
                        blast = true;
                        break;
                    }
                }

                if (!blast) {
                    st.push(nums[i]);
                }
            }
        }

        while (!st.empty()) {
            answer.push_back(st.top());
            st.pop();
        }

        reverse(answer.begin(), answer.end());

        return answer;
    }
};