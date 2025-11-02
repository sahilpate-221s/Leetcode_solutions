class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] answer = new int[n];
        Stack<Integer> st = new Stack<>();

        // Initialize all answers to -1
        Arrays.fill(answer, -1);

        // Loop twice (to simulate circular array)
        for (int i = 0; i < 2 * n; i++) {
            int curr = nums[i % n];

            // While stack not empty and current element is greater
            while (!st.isEmpty() && nums[st.peek()] < curr) {
                answer[st.pop()] = curr;
            }

            // Only push indices from the first pass
            if (i < n) {
                st.push(i);
            }
        }

        return answer;
    }
}
