class Solution {
public:

    bool dfs(int node,vector<int>graph[],vector<int>&vis,vector<int>&inStack){
        
        if(inStack[node]) return true;
        if(vis[node]) return false;

        vis[node] = 1;
        inStack[node] = 1;
        for(auto it : graph[node]){
            
            if(dfs(it,graph,vis,inStack)) return true;
            
        }
        inStack[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {

        vector<int>graph[numCourses+1];

        for(auto it : prereq){
            int u = it[0];
            int v = it[1];
            graph[v].push_back(u);
        }

        vector<int>vis(numCourses+1,0),inStack(numCourses+1,0);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,graph,vis,inStack)) return false;
            }
        }
        return true;

    }
};