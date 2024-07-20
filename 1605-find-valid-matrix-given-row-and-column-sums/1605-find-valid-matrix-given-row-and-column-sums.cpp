class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();

        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<int>colPrefix(m),rowPrefix(n);

        int i,j;

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                
                if(i==0 and j==0){
                    int k = min(rowSum[i],colSum[j]);
                    ans[i][j] = k;
                    rowPrefix[i] += k;
                    colPrefix[j] += k;
                }
                else{

                    int req = rowSum[i] - rowPrefix[i];
                    int req1 = colSum[j] - colPrefix[j];
                    int k = min(req,req1);
                    ans[i][j] = k;
                    rowPrefix[i] += k;
                    colPrefix[j] += k;
                }
            }
        }
        return ans;
    }
};