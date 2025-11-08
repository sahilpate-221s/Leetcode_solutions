class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {

        List<Integer> answer = new ArrayList<>();

        int SR = 0;
        int ER = matrix.length - 1;

        int SC = 0;
        int EC = matrix[0].length - 1;

        while (SR <= ER && SC <= EC) {
            for (int i = SC; i <= EC; i++) {
                answer.add(matrix[SR][i]);
            }
            SR++;

            for (int j = SR; j <= ER; j++) {
                answer.add(matrix[j][EC]);
            }
            EC--;

            if (SR <= ER) {
                for (int i = EC; i >= SC; i--) {
                    answer.add(matrix[ER][i]);
                }
                ER--;
            }

            if (SC <= EC) {
                for (int j = ER; j >= SR; j--) {
                    answer.add(matrix[j][SC]);
                }
                SC++;
            }
        }
        return answer;

    }
}