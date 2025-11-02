class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        stack<int> st;

        int n = nums2.size();

        for (int i = n - 1; i >= 0; i--) {

            int num = nums2[i];

            while (!st.empty() && st.top() <= num) {
                st.pop();
            }

            int greaterVal = st.empty() ? -1 : st.top();
            umap[num] = greaterVal;

            st.push(num);
        }

        vector<int> result;

        for (auto it : nums1) {
            result.push_back(umap[it]);
        }
        return result;
    }
};