class Solution {
    public String removeOuterParentheses(String s) {
        int n = s.length();

        int count = 0;
        StringBuilder str = new StringBuilder(); 

        for(int i=0;i<n;i++)
        {
            if(s.charAt(i) == '(')
            {
                if(count > 0)
                {
                    str.append(s.charAt(i));
                }
                count++;
            }
            else
            {
                count--;
                if(count > 0)
                {
                    str.append(s.charAt(i));
                }
            }
        }
        return str.toString();
        
        
    }
}