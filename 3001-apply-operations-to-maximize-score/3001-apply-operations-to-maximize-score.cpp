class Solution {
public:
    const int mod = 1e9 + 7;
    int calcScore(int x){
        set<int>se;

        while(x%2==0){
            se.insert(2);
            x/=2;
        }

        for(int i = 3;i*i<=x;i+=2){
            while(x%i==0){
                se.insert(i);
                x/=i;
            }
        }
        if(x>1) se.insert(x);

        return se.size();
    }

    int modPower(int a,int b){
        long long ans = 1;
        long long base = a;
        while(b){
            if(b%2==0){
                base = (base * base)%mod;
                b/=2;
            }
            else{
                ans = (ans*base)%mod;
                b--;
            }
        }
        return ans%mod;
    }
    
    int maximumScore(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int>primeScore(n,0);
        int i,j;


        for(i=0;i<n;i++){
            primeScore[i] = calcScore(nums[i]);
        }   

        stack<pair<int,int>>se;
        vector<int>nextGreaterToRight(n,0);
        vector<int>nextGreaterEqualToLeft(n,0);

        for(i=n-1;i>=0;i--){
            if(se.empty()){
                nextGreaterToRight[i] = n;
            }
            else if(se.top().first>primeScore[i]){
                nextGreaterToRight[i] = se.top().second;
            }
            else{
                while(!se.empty() and se.top().first<=primeScore[i]){
                    se.pop();
                }
                if(se.empty()){
                    nextGreaterToRight[i] = n;
                }
                else{
                    nextGreaterToRight[i] = se.top().second;
                }
            }
            se.push({primeScore[i],i});
        }

        while(!se.empty()) se.pop();


        for(i=0;i<n;i++){
            if(se.empty()){
                nextGreaterEqualToLeft[i] = -1;
            }
            else if(se.top().first >= primeScore[i]){
                nextGreaterEqualToLeft[i] = se.top().second;
            }
            else{
                while(!se.empty() and se.top().first < primeScore[i]){
                    se.pop();
                }
                if(se.empty()) nextGreaterEqualToLeft[i] = -1;
                else nextGreaterEqualToLeft[i] = se.top().second;
            }
            se.push({primeScore[i],i});
        }

        priority_queue<pair<int,int>>pq;

        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }

        long long ans = 1;
        while(!pq.empty() and k){
            auto curr = pq.top();
            pq.pop();
            int idx = curr.second;
            int multiplier = curr.first;
            
            int canCoverLeft = idx - nextGreaterEqualToLeft[idx];
            int canCoverRight = nextGreaterToRight[idx]  - idx;

            long long  total = canCoverLeft * 1ll * canCoverRight;
            long long  remMin = min(total,k*1ll);
            ans = (ans * modPower(multiplier,remMin)%mod)%mod;
            k-=remMin;
        }
        return ans;
    }
};