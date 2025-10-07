class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        unordered_map<int, int> umap;
        stack<int> st;

        vector<int> answer;

        for (int i = 0; i < n; i++) {
            int curr = nums2[i];
            while(!st.empty() && st.top() < curr) {
                umap[st.top()] = curr;
                st.pop();
            }
            st.push(curr);
        }

        while (!st.empty()) {
            umap[st.top()] = -1;
            st.pop();
        }

        for (auto it : nums1) {
            answer.push_back(umap[it]);
        }
        return answer;
    }
};