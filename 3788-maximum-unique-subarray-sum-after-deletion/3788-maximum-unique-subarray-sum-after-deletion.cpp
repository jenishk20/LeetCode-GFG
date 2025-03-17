class Solution {
public:
    int maxSum(vector<int>& nums) {
        
        int n = nums.size();
        set<int>se,se1;

        int sum =0 ;
        for(int i=0;i<n;i++){
            if(nums[i]>=0 and !se.count(nums[i])){
                sum += nums[i];
                se.insert(nums[i]);
            }
            else if(nums[i]<0){
                se1.insert(nums[i]);
            }
           
        }
        return se.empty() ? *se1.rbegin(): sum;
    }
};