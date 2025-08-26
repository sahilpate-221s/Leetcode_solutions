class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int answer = 0;
        int maxDiagSq = 0; // stores diagonal squared (l^2 + w^2)
        for (int i = 0; i < dimensions.size(); i++) {
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            int diagSq = l * l + w * w;
            if (diagSq > maxDiagSq) {
                maxDiagSq = diagSq;
                answer = l * w;
            } else if (diagSq == maxDiagSq) {
                // In case of tie in diagonal, choose larger area
                answer = max(answer, l * w);
            }
        }
        return answer;
    }
};
