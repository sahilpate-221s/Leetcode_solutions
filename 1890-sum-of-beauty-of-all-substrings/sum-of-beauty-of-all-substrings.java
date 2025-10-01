class Solution {
    public int beautySum(String s) {

        int n = s.length();

        int count = 0;

        for (int i = 0; i < n; i++) {
            int[] freq = new int[26];

            for (int j = i; j < n; j++) {
                freq[s.charAt(j) - 'a']++;
                int maxi = Integer.MIN_VALUE;
                int mini = Integer.MAX_VALUE;

                for (int it : freq) {
                    if (it > 0) {
                        maxi = Math.max(maxi, it);
                        mini = Math.min(mini, it);
                    }
                }

                count += maxi - mini;
            }
        }
        return count;
    }
}