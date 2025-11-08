class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> answer;
        int SR = 0;
        int ER = matrix.size() - 1;

        int SC = 0;
        int EC = matrix[0].size() - 1;

        while ((SR <= ER) && (SC <= EC)) {
            for (int i = SC; i <= EC; i++) {
                answer.push_back(matrix[SR][i]);
            }
            SR++;

            for (int j = SR; j <= ER; j++) {
                answer.push_back(matrix[j][EC]);
            }
            EC--;

            if (SR <= ER) {
                for (int i = EC; i >= SC; i--) {
                    answer.push_back(matrix[ER][i]);
                }
                ER--;
            }
            if (SC <= EC) {
                for (int j = ER; j >= SR; j--) {
                    answer.push_back(matrix[j][SC]);
                }
                SC++;
            }
        }
        return answer;
    }
};