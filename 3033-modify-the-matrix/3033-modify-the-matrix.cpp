class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        
        map<int,int>ma;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int i,j;
        
        for(i=0;i<m;i++){
            int colMax = 0;
            for(j=0;j<n;j++){
                colMax = max(colMax,matrix[j][i]);
            }
            ma[i] = colMax;
        }
        
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(matrix[j][i] == -1){
                    matrix[j][i] = ma[i];
                }
            }
        }
        return matrix;
    }
};