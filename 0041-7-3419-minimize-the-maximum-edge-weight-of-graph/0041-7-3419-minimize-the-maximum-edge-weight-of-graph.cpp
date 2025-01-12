class Solution {
public:

    bool isValid(int n,int threshold,int maxWeight,vector<vector<int>>&edges){
      
        vector<vector<pair<int, int>>> first(n),second(n),third(n);
        
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(wt<=maxWeight){
                first[v].push_back({u,wt});
            }
        }
        
        queue<int>q;
        q.push(0);
        
        vector<bool>done(n,false);
        done[0] = true;
        int sz = 0;
    
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            sz++;
            for (auto &it : first[f]) {
                
                if (!done[it.first]) {
                    done[it.first] = true;
                    q.push(it.first);
                }
            }
        }
        return sz == n;
    }
    
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        
        vector<pair<int,int>>revGraph[n+1];
        
        int maxi = 0;
        
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            maxi = max(maxi,wt);    
        }
        
        int low = 1;
        int high = maxi;
        int ans = -1;
        
        while(low<=high){
            int mid = (low+high)/2;
            
            if(isValid(n,threshold,mid,edges)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
       
    }
};