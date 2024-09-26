class MyCalendar {
public:
    map<int,int>ma;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        ma[start]++;
        ma[end]--;
        int sum=0;
        for(auto it:ma)
        {
            sum+=it.second;
            if(sum>1){
                ma[start]--;
                ma[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */