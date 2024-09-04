class Solution {
public:
    vector<char>dirs = {'N','E','S','W'};
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        set<pair<int,int>>se;

        for(auto it : obstacles){
            se.insert({it[0],it[1]});
        }

        int currx = 0,curry = 0,dir = 0;
        int ans = 0;

        for(auto it : commands){
            if(it == -1){
                dir = (dir+1)%4;
            }
            else if(it == -2){
                dir = (dir+3)%4;
            }
            else{
                int moves = it;

                while(moves){
                    int nx = currx + dx[dir];
                    int ny = curry + dy[dir];

                    if(se.find({nx,ny}) ==se.end()){
                        currx = nx;
                        curry = ny;
                        moves--;
                        ans = max(ans,currx*currx + curry*curry);
                    }
                    else{
                        break;
                    }

                }
            }
        }
        return ans;
    }
};