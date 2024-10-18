class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    int peekEl = -1;

    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty())
        {
            peekEl = x;
        }
        input.push(x); // har baar karna hai
        
    }
    
    int pop() {
        //amortazed o(1) -> worst me o(n)
        if(output.empty()) // jab output empty hoga tab  o(n)
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        int val = output.top(); // o(1) kab output empty nahi hoga
        output.pop();
        return val;
        
    }
    
    int peek() {
        if(!output.empty())
        {
            return output.top();
        }
        
        return peekEl;
    }
    
    bool empty() {
        if(input.empty() && output.empty())
        {
            return true;
        }
        
        return false;
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