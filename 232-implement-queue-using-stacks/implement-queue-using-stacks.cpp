class MyQueue {
public:
    stack<int>st;
    stack<int>helper;

    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if(helper.empty())
        {

        while(!st.empty())
        {
            helper.push(st.top());
            st.pop();
        }
            }

        int val = helper.top();
        helper.pop();

        return val;
    }
    
    int peek() {
        if(helper.empty())
        {
            while(!st.empty())
            {
                helper.push(st.top());
                st.pop();
            }
        }

        int val = helper.top();
        return val;
    }
    
    bool empty() {
        return st.empty() && helper.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */