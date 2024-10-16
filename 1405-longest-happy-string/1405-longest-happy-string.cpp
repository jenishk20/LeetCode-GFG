class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int,char>>pq;
        
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});
        
        
        if(pq.empty()) return "";
        
        string ans = "";
        char prevChar = ' ';
        
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            
            int rem = curr.first - min(2,curr.first);
            
            if(curr.second == prevChar){
                
                if(pq.empty()) break;
                
                auto next = pq.top();
                pq.pop();
          
                if(curr.first > next.first and next.first>0){
                    ans += string(1,next.second);
                    next.first--;
                }
                else if(next.first>1){
                    ans += string(2,next.second);
                    next.first -=2;
                }
                else if(next.first>0){
                    ans += string(1,next.second);
                    next.first--;
                }
                prevChar = next.second;
                if(curr.first) pq.push(curr);
                if(next.first) pq.push(next);
            }
            else{
                
                int k = min(2,curr.first);
                ans += string(k,curr.second);
                curr.first -= k;
                if(curr.first>0) pq.push(curr);
                prevChar = curr.second;
               
            }
            
        }
        return ans;
    }
};