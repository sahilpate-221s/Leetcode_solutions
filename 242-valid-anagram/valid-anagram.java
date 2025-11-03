class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length())return false;


        HashMap<Character, Integer> umap = new HashMap<>();

        for(int i=0;i<s.length();i++)
        {
            char ch = s.charAt(i);
            umap.put(ch, umap.getOrDefault(ch, 0) + 1);
        }
        
        for(int i=0;i<t.length();i++)
        {
            char ch = t.charAt(i);

            umap.put(ch, umap.getOrDefault(ch,0) - 1);
        }

        for (int value : umap.values()) {
            if (value != 0) return false;
        }
        return true;
    }
}