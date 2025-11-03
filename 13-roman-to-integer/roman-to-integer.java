class Solution {
    public int romanToInt(String s) {
        int number = 0;

        HashMap<Character,Integer> umap = new HashMap<>();

        umap.put('I', 1);
        umap.put('V', 5);
        umap.put('X', 10);
        umap.put('L', 50);
        umap.put('C', 100);
        umap.put('D', 500);
        umap.put('M', 1000);

        int n = s.length();
        for(int i=0;i<s.length()-1;i++)
        {
            char ch = s.charAt(i);
            int digit = umap.get(ch);

            char ch2 = s.charAt(i+1);
            if(umap.get(ch2) > digit)
            {
                number-= digit;
            }
            else
                number+= digit;
        }

        number+= umap.get(s.charAt(n-1));
        return number;
        
    }
}