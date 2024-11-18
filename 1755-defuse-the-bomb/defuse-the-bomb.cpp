class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result;

        if(k==0)
        {
            for(int i=0;i<n;i++)
            {
                result.push_back(0);
            }
            return result;
        }


        int count = k;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            count= abs(k);
            if (k > 0) {
                int j = (i + 1 + n) % n;
                while (count--) {
                    sum += code[(j+n)%n];
                    j++;
                }
                result.push_back(sum);
            } else {
                int j = (i - 1 + n) % n;
                while (count--) {
                    sum += code[(j+n)%n];
                    j--;
                }
                result.push_back(sum);
            }
        }
        return result;
    }
};