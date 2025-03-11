class MovingAverage {
public:
    int sz = 0;
    int sum = 0;
    deque<int>dq;
    MovingAverage(int size) {
        sz = size;
    }
    
    double next(int val) {

        if(dq.size() == sz){
            sum -= dq.front();
            dq.pop_front();
        }

        sum += val;
        dq.push_back(val);
        return (double)sum/dq.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */