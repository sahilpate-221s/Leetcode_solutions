class Solution {
public:
    int compareVersion(string version1, string version2) {

        int v1 = version1.length();
        int v2 = version2.length();

        vector<int> n1;
        vector<int> n2;

        // decoding the version1 string first
        int i = 0;

        while (i < v1) {
            int num = 0;
            while (i < v1 && version1[i] != '.') {
                int digit = version1[i] - '0';
                num = num * 10 + digit;
                i++;
            }
            n1.push_back(num);
            i++;
        }

        int j = 0;
        while (j < v2) {
            int num = 0;
            while (j < v2 && version2[j] != '.') {
                int digit = version2[j] - '0';
                num = num * 10 + digit;
                j++;
            }
            n2.push_back(num);
            j++;
        }

        // now comparign
        i = 0, j = 0;

        while (i < n1.size() || j < n2.size()) {
            int num1 = (i < n1.size()) ? n1[i] : 0;
            int num2 = (j < n2.size()) ? n2[j] : 0;

            if (num1 != num2) {
                return (num1 > num2) ? 1 : -1;
            }

            i++;
            j++;
        }
        return 0;
    }
};