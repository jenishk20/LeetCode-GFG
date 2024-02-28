class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        
        vector<vector<int>>matrix(n,vector<int>(n,1e6));
        
        int i,j,k;
        
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(i==j) matrix[i][j] = 0;
        
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            matrix[u][v] = wt;
            matrix[v][u] = wt;
        }
        
        for(k=0;k<n;k++){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
                }
            }
        }
        
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        
        map<int,int>ma;
        int mini = INT_MAX;
        for(i=0;i<n;i++){
            int cnt = 0;
            for(j=0;j<n;j++){
                if(i!=j && matrix[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            ma[i] = cnt;
            mini = min(mini,cnt);
        }
        
        cout<<mini<<endl;
        int ans = 0;
        for(auto it:ma){
            cout<<it.first<<" "<<it.second<<endl;
            if(it.second == mini){
                ans = max(it.first,ans);
            }
        }
        
        
        return ans;
    }
};