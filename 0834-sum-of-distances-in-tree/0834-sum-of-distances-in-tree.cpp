class Solution {
    
private:
    vector<int>countOfChild,result;
public:
    
    void dfs(int node,vector<int>graph[],int par = -1){
        
        for(auto it : graph[node]){
            if(it == par) continue;
            
            dfs(it,graph,node);
            
            countOfChild[node] += countOfChild[it];
            result[node] += result[it] + countOfChild[it];
        }
        
        countOfChild[node]+=1;
    }
    
        
    void dfs2(int node,vector<int>graph[],int n,int par = -1){
        
        for(auto it : graph[node]){
            if(it == par) continue;
            
            result[it] = result[node] - countOfChild[it] + (n-countOfChild[it]);
            dfs2(it,graph,n,node);
        }
       
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int>graph[n+1];
        
        for(auto it : edges){
            
            int u = it[0];
            int v = it[1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        countOfChild.resize(n,0);
        result.resize(n,0);
        
        dfs(0,graph);
        
        for(int i=0;i<n;i++){
            cout<<countOfChild[i]<<" ";
        }
        
        cout<<result[0]<<endl;
        
        dfs2(0,graph,n);
        
        return result;
        
    }
};