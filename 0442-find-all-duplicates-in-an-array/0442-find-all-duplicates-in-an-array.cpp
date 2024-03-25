class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        
        int i;
        vector<int>ans;
        
        for(i=0;i<n;i++){
           
            int curr = abs(nums[i]);
            int goTo = nums[curr-1];
            
            if(goTo<0){
                ans.push_back(curr);
            }
            else{
                nums[curr-1]*=-1;
            }
            
            
        }
        return ans;
    }
};