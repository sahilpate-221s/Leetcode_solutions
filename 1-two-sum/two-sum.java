class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        int[] answer = new int[2];

        HashMap<Integer, Integer> umap = new HashMap<>();

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = nums[i];

            int rem = target-sum;

            if (umap.containsKey(rem)) {

                answer[0] = i;
                answer[1] = umap.get(rem);
                return answer;
            }
            umap.put(nums[i], i);
        }

        return answer;

    }
}