class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>graph[numCourses+1];
        vector<int>indegree(numCourses+1,0);
        vector<int>ordering;
        
        for(auto i:prerequisites){
            int u = i[0];
            int v = i[1];
            graph[v].push_back(u);
            indegree[u]++;
        }
        
        int i;
        queue<int>q;
        for(i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        int cnt = 0;
        while(!q.empty()){
            int curr = q.front();
            ordering.push_back(curr);
            q.pop();
            
            for(auto itr:graph[curr]){
                indegree[itr]--;
                if(indegree[itr]==0){
                    q.push(itr);
                }
            }
            cnt++;
        }
        
        if(cnt == numCourses){
            return ordering;
        }
        else{
            return {};
        }
    }
};