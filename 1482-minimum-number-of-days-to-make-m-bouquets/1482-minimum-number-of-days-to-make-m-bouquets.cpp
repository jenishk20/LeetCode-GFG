class Solution {
public:
    bool check(int mid,vector<int>&bloomDay,int m,int k){
        
        int sz = bloomDay.size();
        vector<int>blooms(sz,0);
        
        for(int i=0;i<sz;i++){
            if(bloomDay[i]<=mid){
                blooms[i] = 1;
            }
        }
        
        int canPrepare = 0;
        
        for(int i=0;i<sz;i++){
            
            int cnt = 0;
            while(i<sz and blooms[i] == 1){
                cnt++;
                i++;
            }
            canPrepare += cnt/k;
        }
        
        return canPrepare >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        
        if(n<m*1ll*k) return -1;
        
        int low = 1;
        int high = *max_element(bloomDay.begin(),bloomDay.end());
    
        int ans = 0;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            if(check(mid,bloomDay,m,k)){
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