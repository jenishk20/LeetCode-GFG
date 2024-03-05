class Solution {
public:
    int minimumLength(string s) {
        
        deque<char>dq;
        
        for(auto i:s)
            dq.push_back(i);
        
        while(dq.size()>1 && dq.front() == dq.back()){
            
            char first = dq.front();
            while(!dq.empty() && dq.front()==first)
                dq.pop_front();
            
            while(!dq.empty() && dq.back()==first)
                dq.pop_back();
        }
        
        return dq.size();
    }
};