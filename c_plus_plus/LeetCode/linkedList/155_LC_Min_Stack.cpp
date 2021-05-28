class MinStack {
public:
    /** initialize your data structure here. */
    list<int> data;
    list<int> min_data;

    MinStack() {
    }
    
    void push(int val) {
        data.push_back(val);
        if (min_data.size() == 0 || min_data.back() >= val)
            min_data.push_back(val);
    }
    
    void pop() {
        if (data.back() == min_data.back())
            min_data.pop_back();
        data.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return min_data.back();
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
