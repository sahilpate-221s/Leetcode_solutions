class Solution {
    public int beautySum(String s) {
        
        int maxcount = 0;
        int n = s.length();

        for(int i=0;i<n;i++)
        {
            int[] freq = new int[26];
            for(int j=i;j<n;j++)
            {
                int maxi = Integer.MIN_VALUE;
                int mini = Integer.MAX_VALUE;

                int ch = s.charAt(j)- 'a';
                freq[ch]++;

                for(int it: freq)
                {
                    if(it > 0)
                    {
                        maxi = Math.max(maxi, it);
                        mini = Math.min(mini, it);
                    }
                }
                maxcount += maxi - mini;
            }
        }
        return maxcount;
    }
}