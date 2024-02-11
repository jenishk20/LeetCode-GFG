class Solution {
public:
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int r=grid.size();
        int c=grid[0].size();
        
        vector<vector<int>>curr(c,vector<int>(c,0));
        vector<vector<int>>next(c,vector<int>(c,0));
        
        int i,j1,j2;
        for(j1=0;j1<c;j1++)
        {
            for(j2=0;j2<c;j2++)
            {
                if(j1==j2)
                    next[j1][j2]=grid[r-1][j1];
                else
                    next[j1][j2]=grid[r-1][j1]+grid[r-1][j2];
            }
        }
        
        for(i=r-2;i>=0;i--)
        {
            for(j1=0;j1<c;j1++)
            {
                for(j2=0;j2<c;j2++)
                {
                   
                     int maxi=-1e8;
                    for(int dx=-1;dx<=1;dx++)
                    {
                        for(int dy=-1;dy<=1;dy++)
                        {
                            int value=0;
                            if(j1==j2)
                            {
                                value=grid[i][j1];
                            }
                            else
                                value+=grid[i][j1]+grid[i][j2];
                            if(j1+dx>=0 and j2+dy>=0 and j1+dx<c and j2+dy<c)
                            value+=next[j1+dx][j2+dy];
                            else
                            value+=(-1e8);
                            maxi=max(maxi,value);
                        }
                    }
                    curr[j1][j2]=maxi;
                }

            }
            next=curr;
        }
        return next[0][c-1];
        // return recur(0,0,c-1,r,c,grid,dp);
        
    }
};