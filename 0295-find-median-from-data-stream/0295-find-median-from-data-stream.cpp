class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if(maxHeap.empty() || maxHeap.top()>num){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        
        int k1 = minHeap.size();
        int k2 = maxHeap.size();
        cout<<k1<<" "<<k2<<endl;
        if(abs(k2-k1)>1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        
        if(maxHeap.size() == minHeap.size()){
            double res = (double)(maxHeap.top() + minHeap.top())/2.0;
            return res;
        }
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */