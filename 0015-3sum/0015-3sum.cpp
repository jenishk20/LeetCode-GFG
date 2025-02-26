class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());
        int i=0;
        int j=0;

        vector<vector<int>>ansi;
        set<vector<int>>ans;
        for(i=0;i<n;i++){
            int curr = nums[i];
            int l = i+1;
            int r = n-1;
            while(l<r){
                if(nums[l] + nums[r] == -curr){
                    ans.insert({curr,nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(nums[l] + nums[r] < -curr){
                    l++;
                }
                else{
                    r--;
                }
            }
        }

        for(auto it : ans) ansi.push_back(it);
        return ansi;
    }
};