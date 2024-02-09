class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0 || n==1)
            return nums;
        vector<int>dp(n,1);
        sort(nums.begin(),nums.end());
        int i,j;
        int mx=0;
        for(i=1;i<n;i++)
        {
            for(j=i-1;j>=0;j--)
            {
                if(nums[i]%nums[j]==0)
                {
                    int tt=dp[j]+1;
                    if(tt>dp[i])
                        dp[i]=tt;
                }
            }
            mx=max(mx,dp[i]);
        }
        vector<int>ans;
        int prev=0;
        for(i=n-1;i>=0;i--)
        {
            if(dp[i]==mx && prev%nums[i]==0)
            {
                ans.push_back(nums[i]);
                mx--;
                prev=ans.back();
            }
        }
        return ans;
    }
};