class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        int n = grid.size();
        int m = grid[0].size();
        int i,j;
        int sum = 0;
        int gcd = 0;

        vector<int>temp;

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                sum += grid[i][j];
                gcd = __gcd(grid[i][j],gcd);
                temp.push_back(grid[i][j]);
            }
        }

        sort(temp.begin(),temp.end());

        int sz = temp.size();
        int mid = temp[sz/2];
        int ans = 0;
        
        for(i=0;i<sz;i++){
            if((temp[i] - mid)%x != 0) return -1;
            ans += abs(temp[i] - mid)/x;
        }
        return ans;
      
    }
};