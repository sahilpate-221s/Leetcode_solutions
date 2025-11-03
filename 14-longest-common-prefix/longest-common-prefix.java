class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;

        Arrays.sort(strs);

        int i = 0;
        int j  = 0;

        StringBuilder answer = new StringBuilder();

        while( i < strs[0].length() && j < strs[n-1].length())
        {
            char ch1 = strs[0].charAt(i);
            char ch2 = strs[n-1].charAt(j);
            i++;
            j++;

            if(ch1 == ch2)
            {
                answer.append(ch1);
            }
            else
            {
                return answer.toString();
            }
        }
        return answer.toString();
        
    }
}