class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int,char>>pq;
        
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});
        
        
        if(pq.empty()) return "";
        
        string ans = "";
        bool possible = true;
        char prevChar = ' ';
        
        while(!pq.empty() and possible){
            auto curr = pq.top();
            pq.pop();
            
          
            int rem = curr.first - min(2,curr.first);
            cout<<curr.first<<" "<<curr.second<<" "<<
rem<<endl;
            
            if(curr.second == prevChar){
                
                cout<<"Found Equal\n";
                if(pq.empty()) break;
                
                auto next = pq.top();
                pq.pop();
                
                // curr.first -= 2;
                
                cout<<curr.first<<" "<<next.first<<endl;
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
                
                cout<<"Done 1 "<<ans<<endl;
             
            }
            else{
                
                int k = min(2,curr.first);
                ans += string(k,curr.second);
                curr.first -= k;
                if(curr.first>0) pq.push(curr);
                prevChar = curr.second;
                cout<<"Done 2 "<<ans<<endl;
            }
            
        }
        return ans;
    }
};