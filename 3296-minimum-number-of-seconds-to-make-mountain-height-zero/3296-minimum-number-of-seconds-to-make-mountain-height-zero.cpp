class Solution {
public:
    typedef long long ll;
    
    ll findSum(ll mid, ll id){
        
        ll sum = 0;
        ll st = 1;
        
        for(ll i=1;i<=mid;i++){
            sum += st*id;
            st++;
        }
        return sum;
    }
    ll calc(ll workerTimes,ll haveTime){
        
        ll ans = 0;
        ll low = 1;
        ll high = 1e6;
        
        haveTime *= 2;
        haveTime /= workerTimes;
        
        while(low<=high){
            ll mid = (low+high)/2;
            
            if((mid*1ll*(mid+1))<=haveTime){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
    bool check(ll time,vector<int>&workerTimes,int mountainHeight){
        
        
        ll done = 0;
        
        for(int i=0;i<workerTimes.size();i++){
            
            ll haveTime = time;
            ll findMaxMul = calc(workerTimes[i],haveTime);
            
            // cout<<time<<" "<<findMaxMul<<endl;
            done += findMaxMul;
            
        }
        
        return done >= mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        ll low = 0;
        ll high = 1e18;
        ll ans = 0;
        
        sort(workerTimes.begin(),workerTimes.end());
        
        while(low<=high){
            ll mid = low+(high-low)/2;
            
            if(check(mid,workerTimes,mountainHeight)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};