class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        
        long long r=points.size();
        long long c=points[0].size();
        
        int i,j;
        long long dp[r][c];
        for(i=0;i<c;i++)
        {
            dp[0][i]=points[0][i];
        }
        for(i=1;i<r;i++)
        {
            vector<long long>left(c),right(c);
            
            left[0]=dp[i-1][0];
            for(j=1;j<c;j++)
            left[j]=max(left[j-1],dp[i-1][j]+j);
            
            right[c-1]=dp[i-1][c-1]-(c-1);
            for(j=c-2;j>=0;j--)
                right[j]=max(right[j+1],dp[i-1][j]-j);
            
            
            for(j=0;j<c;j++)
            {
                dp[i][j]=max(left[j]-j,right[j]+j)+points[i][j];
            }
            
            
                
        }
        long long ans=0;
        for(i=0;i<c;i++)
            ans=max(ans,dp[r-1][i]);
        return ans;
    }
};