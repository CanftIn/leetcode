class MinStack {
    stack<int> val_stack;
    stack<int> min_stack;

public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int val) {
        val_stack.push(val);
        min_stack.push(min(min_stack.top(), val));
    }
    
    void pop() {
        val_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return val_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
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