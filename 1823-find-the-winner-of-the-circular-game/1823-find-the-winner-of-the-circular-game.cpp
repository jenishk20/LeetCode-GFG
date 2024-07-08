class Solution {
public:
    int findTheWinner(int n, int k) {
        
        deque<int>dq;
        
        for(int i=1;i<=n;i++){
            dq.push_back(i);
        }
        
        while(dq.size()!=1){
            
            cout<<dq.front()<<endl;
            for(int i=0;i<k-1;i++)
            {
                int curr = dq.front();
                dq.pop_front();
                dq.push_back(curr);
            }
            dq.pop_front();
        }
        return dq.front();
    }
};