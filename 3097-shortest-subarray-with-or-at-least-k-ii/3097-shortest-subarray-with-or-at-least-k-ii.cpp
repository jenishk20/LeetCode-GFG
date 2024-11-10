class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        
        int i=0,j=0,n = nums.size();
        for(i=0;i<n;i++){
            if(nums[i]>=k) return 1;
        }
        
        vector<int>bits(32,0);
        int windowOr = 0;
        int ans = 1e9;
        i=0;
        j=0;
        
        while(j<n){
            
            windowOr |= nums[j];
            for(int k=0;k<=31;k++){
                if(nums[j]&(1<<k)) bits[k]++;
            }
           
            while(windowOr >= k){
                ans = min(ans, j-i+1);
               
                for(int k=0;k<=31;k++){
                    if(nums[i]&(1<<k)){
                        if(bits[k]>1){
                            bits[k]--;
                        }
                        else{
                            bits[k]--;
                            windowOr = windowOr ^ (1<<k);
                        }
                    }
                }
                i++;
            }
            j++;
        }
        
        return ans == 1e9 ? -1 : ans;
    }
};