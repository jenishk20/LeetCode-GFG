class Solution {
public:
    vector<int> checkForCycle(vector<int>graph[],vector<int>&indegree,int k)
    {
        queue<int>q;
       for(int i=1;i<=k;i++)
       {
           if(indegree[i]==0)
               q.push(i);
       }
        int c=0;
        vector<int>ordering;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
           // ordering[curr]=c++;
            ordering.push_back(curr);
            for(auto i:graph[curr])
            {
                indegree[i]--;
                if(indegree[i]==0)
                    q.push(i);
            }
            c++;
            
        }
        if(c!=k) return {};
        return ordering;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
         int n;
        vector<int>rowGraph[k+1],colGraph[k+1];
        vector<int>rowIndegree(k+1,0),colIndegree(k+1,0);
        for(auto i:rowConditions)
        {
            int u=i[0];
            int v=i[1];
            rowGraph[u].push_back(v);
            rowIndegree[v]++;
        }
        for(auto i:colConditions)
        {
            int u=i[0];
            int v=i[1];
            colGraph[u].push_back(v);
            colIndegree[v]++;
        }
        
        vector<int> b1=checkForCycle(rowGraph,rowIndegree,k);
        vector<int> b2=checkForCycle(colGraph,colIndegree,k);
        
        if(b1.size()==0 or b2.size()==0) return {};

        vector<vector<int>>ans(k,vector<int>(k,0));
        int i,j;
        
        map<int,int>ma;
        for(i=0;i<b2.size();i++)
            ma[b2[i]]=i;

        for(i=0;i<k;i++)
        {
            int ele = b1[i];
            int pos = ma[ele];
            ans[i][pos] = ele;    
        }
        return ans;
    }
};