class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ops = 0;
        int n = nums.size()-1;
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(auto it : nums) pq.push(it);

        while(pq.size()>1){
            long long p1 = pq.top();
            pq.pop();
            if(p1>=k) return ops;
            long long p2 = pq.top();
            pq.pop();

            long long k1 = min(p1,p2);
            long long k2 = max(p1,p2);
            long long up = LLONG_MAX/2;
            if(k1>=up) continue;

            if(k1*2ll >= LLONG_MAX-k2) continue;

            pq.push(k1*2ll + k2);
            ops++;
        }
        return ops;

    }
};