class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        vector<pair<int,int>>ve;
        
        int n = profits.size();
        
        priority_queue<int>pq;
        
        int i,j;
        
        for(i=0;i<n;i++){
            ve.push_back({capital[i],profits[i]});
        }
        
        sort(ve.begin(),ve.end());
        
        i=0;
        while(k){
            
            while(i<n and ve[i].first<=w){
                pq.push(ve[i].second);
                i++;
            }
            
            if(pq.empty()) break;
            
            w+=pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};