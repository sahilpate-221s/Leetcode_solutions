class Solution {
public:
    vector<vector<string>> answer;
    vector<string> temp;

    void solve(int idx, string& s) {
        if (idx == s.length()) {
            answer.push_back(temp);
            return;
        }

        string present = "";

        for (int i = idx; i < s.length(); i++) {
            present += s[i];

            if (isPal(present)) {
                temp.push_back(present);
                solve(i + 1, s);
                temp.pop_back();
            }
        }
    }

    bool isPal(string str) {
        int i = 0;
        int j = str.length() - 1;

        while (i < j) {
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        solve(0, s);
        return answer;
    }
};