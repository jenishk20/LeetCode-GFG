class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        map<int,int>row,col;
        int i,j;
        for(i=0;i<n;i++){
            int cnt = 0;
            for(j=0;j<m;j++){
                if(grid[i][j]) cnt++;
            }
            row[i] = cnt;
        }

        for(i=0;i<m;i++){
            int cnt = 0;
            for(j=0;j<n;j++){
                if(grid[j][i]) cnt++;
            }
            col[i] = cnt;
        }

        int res = 0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j] and (row[i]>=2 or col[j]>=2)) res++;
            }
        }
        return res;
    }
};