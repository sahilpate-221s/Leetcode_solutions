class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size())
            return -1;

        int n = needle.length();

        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                if (haystack.substr(i, n) == needle) {
                    return i;
                }
            }
        }
        return -1;
    }
};