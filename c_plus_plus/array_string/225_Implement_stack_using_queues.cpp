class MyStack {
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        int size = q.size() - 1;
        while(size--) {
            x = q.front();
            q.pop();
            q.push(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (q.size() == 0)
            return -1;
        int x = q.front();
        q.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        if (q.size() == 0)
            return -1;
        int x = q.front();
        return x;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
