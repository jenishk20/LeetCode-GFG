class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        long  sumOfFirstN = n*n*(n*n+1)/2;
        long  sumOfSquareFirstN = n*1ll*n*(n*1ll*n+1)*(2*1ll*n*1ll*n+1)/6;

        long gridSum = 0;
        long gridSumSquare = 0;


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                gridSum += grid[i][j];
                gridSumSquare += (grid[i][j] * grid[i][j]);
            }
        }

        long diffOf2 = gridSum - sumOfFirstN;
        long diffOfSquare = gridSumSquare - sumOfSquareFirstN;

        long o1 = diffOfSquare / diffOf2;


        int a = (o1 + diffOf2) / 2;
        int b = (o1 - diffOf2) / 2;

        return {a,b};

    }
};