class Solution {
public:
    const int mod = 1e9+7;
    int powMod(long long base,int expo){
        long long res = 1;

        while(expo){
            if(expo&1){
                res = (res*1ll*base)%mod;
                expo--;
            }
            else{
                base = (base*1ll*base)%mod;
                expo/=2;
            }
        }
        return res;
    }

    int inverseMod(int a){
        return powMod(a,mod-2)%mod;
    }

    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int>fact(1e5+1,1),ifact(1e5+1);
    
        for(int i=1;i<=1e5;i++){
            fact[i] = (i*1ll*fact[i-1])%mod;
        }
        
        ifact[1e5] = inverseMod(fact[1e5]);
        for(int i = 1e5-1;i>=0;i--){
            ifact[i] = (ifact[i+1]*1ll*(i+1))%mod;
        }

        vector<long long>pdp(n,0ll);
        int sum = 0;

        for(int i=0;i<n;i++){
            for(int j=1;j<=k;j++){
                int available = i;
                int req = j-1;
                int cnt = 0;
                if(req == 0 || available == req) cnt++;
                else if(available != 0 and available>req){
                    int numo = fact[available];
                    int deno = (ifact[available-req]*1ll*ifact[req])%mod;
                   
                    cnt += (numo*1ll*deno)%mod;
                }
                pdp[i] += cnt;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j = 1;j<=k;j++){
                int available = n-i-1;
                int req = j-1;
                int cnt = 0;
                if(req == 0 || available == req) cnt++;
                else if(available != 0 and available>req){
                    int numo = fact[available];
                    int deno = (ifact[available-req]*1ll*ifact[req])%mod;
                    cnt += (numo*1ll*deno)%mod;
                }
                pdp[i] += cnt;
            }
        }

        for(int i=0;i<n;i++){
            int ans = (pdp[i]%mod*nums[i]%mod)%mod;
            sum = (sum + ans)%mod;
        }

        return sum;
    }
};