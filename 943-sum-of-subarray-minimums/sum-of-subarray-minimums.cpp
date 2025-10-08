class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();


        int  mod = 1e9+ 7;

        vector<int>left(n),right(n);

        stack<pair<int,int>>st;

        // finding the smaller element previous to the current 
        for(int i=0;i<n;i++)
        {
            int count = 1;
            while(!st.empty() && st.top().first > arr[i])
            {
                count+= st.top().second;
                st.pop();
            }

            left[i] = count;
            st.push({arr[i],count});
        }

        // clearing the stack
        while(!st.empty())st.pop();

        // Finding the smaller element next to the current element
        
        for(int i=n-1;i>=0;i--) 
        {
            int count = 1;
            while(!st.empty() && st.top().first >= arr[i])
            {
                count+= st.top().second;
                st.pop();
            }
            right[i] = count;
            st.push({arr[i],count}); 
        }

        // now multiply current element * leftcount * rightcount;

        long long answer = 0;
        for(int i=0;i<n;i++)
        {
            answer = (answer + (long long )arr[i] * left[i] * right[i]) % mod;
        }
        return answer;

        
    }
};