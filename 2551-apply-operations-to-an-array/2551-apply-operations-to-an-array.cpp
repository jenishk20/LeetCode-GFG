class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        
        int n = nums.size();
        int i,j;
        
        for(i=0;i<n-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i]*=2;
                nums[i+1] = 0;
            }
        }

        for(i=0;i<n;i++){
            for(j=0;j<n-1;j++){
                if(nums[j] == 0 and nums[j+1] != 0){
                    swap(nums[j],nums[j+1]);
                }
            }
        }
        return nums;
    }
};