class Solution {
    public boolean isIsomorphic(String s, String t) {
        int slen = s.length();
        int tlen = t.length();

        if (slen != tlen)
            return false;

        HashMap<Character, Character> smap = new HashMap<>();
        HashMap<Character, Character> tmap = new HashMap<>();

        for (int i = 0; i < slen; i++) {
            char sval = s.charAt(i);
            char tval = t.charAt(i);

            if (smap.containsKey(sval)) {
                if (smap.get(sval) != tval)
                    return false;
            } else if (tmap.containsKey(tval)) {
                if (tmap.get(tval) != sval)
                    return false;
            }

            smap.put(sval, tval);
            tmap.put(tval, sval);
        }
        return true;

    }
}