class Solution {
public:
    string pushDominoes(string dominoes) {
        string answer = "";

        int n = dominoes.length();
        vector<int> right(n, 0);
        vector<int> left(n, 0);
        int RF = 0;
        int LF = 0;

        // Right force propagation
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') {
                RF = n;
            } else if (dominoes[i] == 'L') {
                RF = 0;
            } else {
                RF = max(RF - 1, 0);
            }
            right[i] = RF;
        }

        // Left force propagation
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                LF = n;
            } else if (dominoes[i] == 'R') {
                LF = 0;
            } else {
                LF = max(LF - 1, 0);
            }
            left[i] = LF;
        }

        // Final result based on force comparison
        for (int i = 0; i < n; i++) {
            if (left[i] > right[i]) {
                answer += 'L';
            } else if (right[i] > left[i]) {
                answer += 'R';
            } else {
                answer += '.';
            }
        }

        return answer;
    }
};
