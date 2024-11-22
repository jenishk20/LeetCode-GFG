class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        map<string,int>ma;
        
        for(int i=0;i<n;i++){
            char st = matrix[i][0];
            string res = "B";
            for(int j=1;j<m;j++){
                if(matrix[i][j] == st){
                    res += "B";
                }
                else{
                    res += "C";
                }
            }
            ma[res]++;
        }
        
        int maxi = 0;
        for(auto it : ma){
            maxi = max(maxi,it.second);
        }
        
        return maxi;
    }
};