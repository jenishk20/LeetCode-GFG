class Solution {
public:
    typedef long long ll;

    ll calc(ll workerTimes,ll haveTime){
        
       
        haveTime *= 2;
        haveTime /= workerTimes;
        
        double det = 1 + 4*haveTime;
        
        double d1 = -1 + sqrt(det) / 2.0;
        double d2 = -1 - sqrt(det) / 2.0;
        
        // cout<<haveTime<<" "<<det<<" "<<d1<<" "<<d2<<endl;
        
        d1 = ceil(d1);
        
        if(d1*d1 + d1 - haveTime <= 0) return d1;
        else return --d1;
        
        d2 = ceil(d2);
        
        if(d2*d2 + d2 - haveTime <= 0) return d2;
        else return --d2;
      
    }
    bool check(ll time,vector<int>&workerTimes,int mountainHeight){
        
        
        ll done = 0;
        
        for(int i=0;i<workerTimes.size();i++){
            ll haveTime = time;
            ll findMaxMul = calc(workerTimes[i],haveTime);
            
            // cout<<"HERE "<<workerTimes[i]<<" "<<findMaxMul<<endl;
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