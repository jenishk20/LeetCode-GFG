class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        long long sum = 0;
        int negCount = 0;
        int mini = 1e9;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] < 0){
                    negCount++;
                }
                sum += abs(matrix[i][j]);
                
                if(abs(matrix[i][j])<mini) mini = abs(matrix[i][j]);
            }
        }
        
        if(negCount%2==0) return sum;
        
        return sum - 2*mini;
        
    }
};