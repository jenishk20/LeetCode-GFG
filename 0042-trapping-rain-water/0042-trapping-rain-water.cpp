class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        
        vector<int>pfx(n,0),sfx(n,0);
        int i;
        pfx[0]=height[0];
        for(i=1;i<n;i++)
        {
            pfx[i]=max(pfx[i-1],height[i]);
        }
        sfx[n-1]=height[n-1];
        for(i=n-2;i>=0;i--)
        {
            sfx[i]=max(sfx[i+1],height[i]);
        }
        int ans=0;
        for(i=0;i<n;i++)
        {
            int tt=min(pfx[i],sfx[i])-height[i];
            ans+=tt;
        }
        return ans;
        
    }
};