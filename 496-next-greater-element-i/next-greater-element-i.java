class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {

        int n = nums2.length;
        HashMap<Integer, Integer> umap = new HashMap<>();
        Stack<Integer> st = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {
            int ch = nums2[i];
            while (!st.isEmpty() && st.peek() <= ch) {
                st.pop();
            }

            int value = st.empty() ? -1 : st.peek();

            umap.put(ch, value);
            st.push(ch);
        }

        int[] answer = new int[nums1.length];

        for (int i = 0; i < nums1.length; i++) {
            answer[i] = umap.get(nums1[i]);
        }
        return answer;
    }
}