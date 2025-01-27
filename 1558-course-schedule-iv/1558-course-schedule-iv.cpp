class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prq, vector<vector<int>>& qu) {
      
        
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX/2));
        vector<bool>ans;
      //  ans.push_back(false);
        int i,j,k;
        for(i=0;i<prq.size();i++)
        {
            dp[prq[i][0]][prq[i][1]]=1;
        }
        
        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(dp[i][j]>dp[i][k]+dp[k][j])
                        dp[i][j]=dp[i][k]+dp[k][j];
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        for(i=0;i<qu.size();i++)
        {
            if(dp[qu[i][0]][qu[i][1]]!=INT_MAX/2)
                ans.push_back(1);
            else
                ans.push_back(0);
        }
        return ans;
        
    }
};