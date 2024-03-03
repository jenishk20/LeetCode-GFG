class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<long,vector<long>,greater<long>>pq;
        
        for(auto i:nums)
            pq.push(i);
        
        int cnt = 0;
        while(pq.size()>=2){
            
            long p1 = pq.top();
            pq.pop();
            
            long p2 = pq.top();
            pq.pop();
            
            
            if(p1>=k) return cnt;
            
            pq.push(min(p1,p2)*2 + max(p1,p2));
            
            cnt++;
            
        }
        
        return cnt;
            
    }
};