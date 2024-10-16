class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> result(n); 

        // //brute force 
        // for(int i=0;i<n;i++)  
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(temp[j] > temp[i])
        //         {
        //             result[i] = j-i;
        //             break;
        //         }
        //     }
        // }
        // return result;


        //optimal code
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && temp[i] >= temp[st.top()])
            {
                st.pop();
            }

            if(st.empty())
            {
                result[i]=0;
            }
            else
            {
                result[i] = st.top()-i;
            }


            st.push(i);
        }
        return result;


    }
};