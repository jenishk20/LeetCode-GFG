class MyCircularDeque {
public:
    vector<int>deque;
    
    int front,rear;
    int currentCount;
    int k;
    
    MyCircularDeque(int k) {
        this->k = k;
        deque.resize(k);
        front = 0;
        rear = k-1;
        currentCount = 0;
        
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        
        
        front = (front - 1 + k)%k;
        deque[front] = value;
        
        currentCount++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        
        rear = (rear + 1)%k;
        deque[rear] = value;
        
       
        currentCount++;
        return true;
    }
    
    bool deleteFront() {
        
        if(isEmpty()){
            return false;
        }
        
        front = (front + 1)%k;    
        currentCount--;
        return true;
        
    }
    
    bool deleteLast() {
        
        if(isEmpty()){
            return false;
        }
        
        rear = (rear - 1 + k)%k;
        currentCount--;
        return true;
    }
    
    int getFront() {
        
        if(isEmpty()) return -1;
        
        return deque[front];
    }
    
    int getRear() {
        
        if(isEmpty()) return -1;
        
        return deque[rear];
        
    }
    
    bool isEmpty() {
        return currentCount == 0;
    }
    
    bool isFull() {
        return currentCount == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */