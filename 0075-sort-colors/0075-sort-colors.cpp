class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>bucket(3,0);
        
        for(auto it : nums){
            bucket[it]++;
        }
        
        for(int i=0,val=0;val<=2;val++){
            for(int j=0;j<bucket[val];j++){
                nums[i++] = val;
            }
        }
        
        
            
    }
};