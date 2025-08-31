class MinStack {
public:
    stack<int> st;
    stack<int> minStack;

    MinStack() {}

    void push(int val) {
        st.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        int val = st.top();
        if (val == minStack.top()) {
            minStack.pop();
        }
        st.pop();
        // return val;
    }

    int top() { return st.top(); }

    int getMin() {
        if (minStack.empty())
            return -1;
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */