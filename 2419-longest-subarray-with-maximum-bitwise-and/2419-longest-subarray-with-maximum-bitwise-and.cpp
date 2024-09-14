class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int maxi = 0;
        int n = nums.size();
        
        for(auto it : nums){
            maxi = max(maxi,it);
        }
        
        int len = 0;
        
        for(int i=0;i<n;i++){
            if(nums[i] == maxi){
                
                int currRes = nums[i];
                int ans = 1;
                cout<<currRes<<endl;
                while(i+1<n and (currRes&nums[i+1]) == maxi){
                    ans++;
                    i++;
                }
                len = max(len,ans);
            }
        }
        return len;
    }
};