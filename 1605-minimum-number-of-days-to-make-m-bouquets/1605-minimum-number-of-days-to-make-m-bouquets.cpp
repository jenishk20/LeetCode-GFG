class Solution {
public:
    bool check(int mid,int m,int k,vector<int>&bloomDay){
        vector<int>checker(bloomDay.size(),0);

        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= mid) checker[i] = 1;
        }
        int cnt = 0;
        int ans = 0;
        for(int i=0;i<checker.size();i++){
            if(checker[i]){
                cnt++;
                if(cnt >= k){
                    cnt = 0;
                    ans++;
                }
            }
            else{
                cnt = 0;
            }
        }
        return ans>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        int low = 0;
        int high = *max_element(bloomDay.begin(),bloomDay.end());

        int ans = -1;
        while(low<=high){
            int mid = (low + high)/2;
            if(check(mid,m,k,bloomDay)){
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