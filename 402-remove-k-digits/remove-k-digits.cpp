class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n= num.size();
        stack<char>st;

        for(auto c: num)
        {
            // Jab tak top element bada hai aur hum remove kar sakte hain
            while(!st.empty() && k > 0 && st.top() > c)
            {
                st.pop();
                k--;
            }
            st.push(c);
        }

        //agar abhi bhi koi digits bachi ho remove karne ko
        while(k > 0 && !st.empty())
        {
            st.pop();
            k--;
        }

        //stack se number banao reverse banega
        string res = "";

        while(!st.empty())
        {
            res+= st.top();
            st.pop();
        }
        reverse(begin(res),end(res));


        int i=0;
        //leading zeros hatana hai
        while(i < res.size() && res[i] == '0') i++;

        res = res.substr(i);


        if(res == "")return "0";

        return res;



    }
};