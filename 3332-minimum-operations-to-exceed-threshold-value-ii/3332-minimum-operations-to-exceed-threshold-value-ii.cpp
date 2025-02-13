class Solution {
public:
    long long findAns(vector<int>&nums,int ops){
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(auto it : nums) pq.push(it);

        long long mini = LLONG_MAX;
        while(pq.size()>1 and ops--){

            int p1 = pq.top();
            pq.pop();
            int p2 = pq.top();
            pq.pop();

            long long k = min(p1,p2);
            long long k1 = max(p1,p2);

            if(k*1ll>=(LLONG_MAX/2)){
                return LLONG_MAX;
            }

            long long tempa = k*2ll;
            cout<<k<<" "<<k1<<endl;
            if(tempa >= LLONG_MAX - k1){
                return LLONG_MAX;
            }
            tempa += k1;
            cout<<tempa<<endl;
            pq.push(tempa);
        }
        return pq.top();
    }
    int minOperations(vector<int>& nums, int k) {
        int ops = 0;
        int n = nums.size()-1;
        
        // int low = 0;
        // int high = n;
        // int ans = 1e9;
        // while(low<=high){

        //     int mid = (low+high)/2;
        //     long long miniAfterMid = findAns(nums,mid);
        //     if(miniAfterMid>=k){
        //         ans = mid;
        //         high = mid-1;
        //     }
        //     else{
        //         low = mid+1;
        //     }
        // }
        // return ans;

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