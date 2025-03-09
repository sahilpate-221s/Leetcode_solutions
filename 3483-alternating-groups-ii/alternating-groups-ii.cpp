class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        
        int n = colors.size();
        int ans = 0;

        if (k > n) return 0;

        bool isAlter = true;
        for (int j = 0; j < k - 1; j++) {
            if (colors[j] == colors[j + 1]) {
                isAlter = false;
                break;
            }
        }
        if (isAlter) ans++;

         for (int i = 1; i < n; i++) {
            
            if (colors[(i - 1) % n] == colors[(i - 1 + 1) % n]) {
                isAlter = false;
            }
            if (colors[(i + k - 2) % n] == colors[(i + k - 1) % n]) {
                isAlter = false;
            }
            if (isAlter) {
                ans++;
            } else {
                isAlter = true;
                for (int j = 0; j < k - 1; j++) {
                    if (colors[(i + j) % n] == colors[(i + j + 1) % n]) {
                        isAlter = false;
                        break;
                    }
                }
                if (isAlter) ans++;
            }
        }

        return ans;

    }
};