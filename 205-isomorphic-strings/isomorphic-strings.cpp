class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length())
            return false;

        unordered_map<char, char> smap;
        unordered_map<char, char> tmap;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            char th = t[i];

            if (smap.find(ch) != smap.end()) {
                if (smap[ch] != th)
                    return false;
            } else if (tmap.find(th) != tmap.end()) {

                if (tmap[th] != ch)
                    return false;
            }

            smap[ch] = th;
            tmap[th] = ch;
        }
        return true;
    }
};