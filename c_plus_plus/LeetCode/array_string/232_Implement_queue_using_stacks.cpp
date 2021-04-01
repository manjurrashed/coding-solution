class MyQueue {
    stack<int> s;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        int size = s.size();
        stack<int> temp;
        while (size--) {
            temp.push(s.top());
            s.pop();
        }
        s.push(x);
        size = temp.size();
        while (size--) {
            s.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s.empty()) return -1;
        int x = s.top();
        s.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if (s.empty()) return -1;
        int x = s.top();
        return x;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
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
