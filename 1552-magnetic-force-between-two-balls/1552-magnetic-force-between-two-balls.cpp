class Solution {
public:
    bool check(int force,vector<int>&position,int m){
       
        int i = 0;
        int n = position.size();
        int currPos = position[0];
        m--;
        for(i=1;i<n;i++){
            if(position[i] - currPos >= force){
                m--;
                currPos = position[i];
            }
        }
        return m<=0;
    }
    int maxDistance(vector<int>& position, int m) {
        
        int n = position.size();
        int low = 0;
        int high = 1e9;
        int ans = 0;
        sort(position.begin(),position.end());
        
        while(low<=high){
            int mid = (low+high)/2;
            
            if(check(mid,position,m)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};