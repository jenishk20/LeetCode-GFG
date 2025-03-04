class MinStack {
public:
    stack<pair<int,int>>se;
    MinStack() {
        
    }
    
    void push(int val) {
        if(se.empty()){
            se.push({val,val});
        }
        else{
            int k = se.top().second;
            se.push({val,min(k,val)});
        }
    }
    
    void pop() {
        se.pop();
    }
    
    int top() {
        return se.top().first;
    }
    
    int getMin() {
        return se.top().second;
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