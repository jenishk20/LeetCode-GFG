class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int minVal = INT_MAX;
        
        vector<int>prev(m,0);

        
        for(int i=0;i<n;i++){
            
            vector<int>curr(m,INT_MAX);
            
            for(int j=0;j<m;j++){
                
                if(i==0) {
                    prev[j] = matrix[i][j];
                    continue;
                }
                
                int op1,op2 = INT_MAX ,op3 = INT_MAX;
                
               
                op1 = matrix[i][j] + prev[j];
                
                if(j-1>=0)
                op2 = matrix[i][j] + prev[j-1];
                
                if(j+1<m)
                op3 = matrix[i][j] + prev[j+1];
                
                curr[j] = min({op1,op2,op3});
            }
            if(i!=0)
            prev = curr;
        }
        
        
        
        
        for(int i=0;i<m;i++){
            
            minVal = min(minVal,prev[i]);
        }
        
        return minVal;
    }
};