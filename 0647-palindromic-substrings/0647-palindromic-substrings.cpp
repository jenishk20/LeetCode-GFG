class Solution {
public:
    int dp[1001][1001];
    int recur(int i,int j,string &s)
    {
        if(i>j)
            return 1;
        if(i==j)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]!=s[j])
            return 0;
        
        return dp[i][j]= recur(i+1,j-1,s);
    }
    int countSubstrings(string s) {
        memset(dp,-1,sizeof dp);
        int n=s.size();
        int i,j;
        
        int ans=0;
        
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                ans+=recur(i,j,s);
               // cout<<i<<" "<<j<<endl;
            }
        }
        return ans;
    }
};