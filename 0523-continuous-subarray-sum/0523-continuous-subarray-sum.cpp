class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       
        int n = nums.size();
        int sum = 0;
        map<int,int>ma;
        
        ma[0] = -1;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            if(ma.find(sum%k)!=ma.end()){
                
                int foundAt = ma[sum%k];
                if(i-foundAt>=2){
                    return true;
                }
            }
            else{
                ma[sum%k] = i;
            }
        }
        return false;
    }
};