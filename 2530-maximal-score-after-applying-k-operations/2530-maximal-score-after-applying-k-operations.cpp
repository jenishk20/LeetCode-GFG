class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        long long sum = 0;
        
        priority_queue<int>pq;
        for(auto it : nums) pq.push(it);
        
        while(k--){
            auto curr = pq.top();
            pq.pop();
            sum += curr;
            
            pq.push(ceil((double)curr/3));
        }
        
        return sum;
    }
};