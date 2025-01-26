class Solution {
public:
    int bfs(int node,int n,unordered_map<int,vector<int>>&graph,int other){
        vector<int>vis(n+1,0);
        vis[node] = 1;
        vis[other] = 1;
        queue<pair<int,int>>q;
        q.push({node,0});
        int res = 0;

        while(!q.empty()){
            int curr = q.front().first;
            int cntNodes = q.front().second;
            q.pop();

            for(auto it : graph[curr]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,cntNodes+1});
                    res = max(res,cntNodes+1);
                }
            }
        }

        return res;
    }
    int maximumInvitations(vector<int>& favorite) {
        
        int n = favorite.size();
        int i,j,k;
        unordered_map<int,vector<int>>graph;

        for(i=0;i<n;i++){
            graph[favorite[i]].push_back(i);
        }

        int maxCycle = 0;
        int twoCycleLength = 0;

        vector<bool>vis(n,false);
       
        for(int i=0;i<n;i++){
            if(!vis[i]){
                unordered_map<int,int>countSeen;
                int cnt = 0;
                int curr = i;
                while(!vis[curr]){
                    vis[curr] = 1;
                    countSeen[curr] = cnt;
                    int nextNode = favorite[curr];
                    cnt++;

                    if(countSeen.count(nextNode)){
                        int cycleLength = cnt - countSeen[nextNode];
                        maxCycle = max(maxCycle, cycleLength);

                        if(cycleLength == 2){
                            
                            int res = 2 + bfs(curr,n,graph,nextNode) + bfs(nextNode,n,graph,curr);
                            twoCycleLength += res;
                        }
                        break;
                    }
                    curr = nextNode;
                }
            }
        }
        return max(maxCycle,twoCycleLength);
    }
};