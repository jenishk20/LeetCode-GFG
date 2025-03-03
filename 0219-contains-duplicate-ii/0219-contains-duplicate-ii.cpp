class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int i;

        map<int,int>ma;
        for(i=0;i<n;i++){
            if(ma.find(nums[i])!= ma.end()){
                if(i-ma[nums[i]]<=k) return true;
            }
            ma[nums[i]] = i;
        }   
        return false;
    }
};