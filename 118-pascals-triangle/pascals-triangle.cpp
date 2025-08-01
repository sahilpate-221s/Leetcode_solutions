class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>answer(numRows);


        for(int i=0;i<numRows;i++)
        {
            // har ith index ke liye 1 vector chahiye
            answer[i] = vector<int>(i+1,1);

            // ek j loop lagega jo colums traverse karegas
            for(int j=1;j<i;j++)
            {
                answer[i][j] = answer[i-1][j] + answer[i-1][j-1];
            }
        }

        return answer;

        
    }
};