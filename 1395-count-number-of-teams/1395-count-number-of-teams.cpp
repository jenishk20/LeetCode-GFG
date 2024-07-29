class Solution {
public:
    int numTeams(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++){

            vector<int>prev(2),next(2);
            for(int j=i-1;j>=0;j--){
                if(nums[j]>nums[i]) prev[1]++;
                else if(nums[j]<nums[i]) prev[0]++;
            }

            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]) next[1]++;
                else if(nums[j]<nums[i]) next[0]++;
            }

            ans += (prev[0] * next[1]) + (prev[1] * next[0]);
        }
        return ans; 
    }
};