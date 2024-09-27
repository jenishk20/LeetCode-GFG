class MyCalendarTwo {
public:
    map<int,int>ma;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        ma[start]++;
        ma[end]--;
        int sum=0;
        for(auto it:ma)
        {
            sum+=it.second;
            if(sum>2){
                ma[start]--;
                ma[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */