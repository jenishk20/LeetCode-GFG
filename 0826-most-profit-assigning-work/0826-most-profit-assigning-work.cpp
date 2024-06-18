class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        vector<pair<int,int>>ve;
        map<int,int>ma;
        
        int n = difficulty.size();
        int m = worker.size();
        int i,j;
        
        for(i=0;i<n;i++){
            
            if(ma.find(difficulty[i])!=ma.end()){
                ma[difficulty[i]] = max(ma[difficulty[i]],profit[i]);
            }
            else
                ma[difficulty[i]] = profit[i];
        }
        
        int sum = 0;
        
        for(auto it : ma){
            sum = max(sum,it.second);
            ve.push_back({it.first,sum});
        }
           
        int res = 0;
        for(i=0;i<m;i++){
            
            int low = 0;
            int high = ve.size()-1;
            int ans = 0;
            while(low<=high){
                
                int mid = low+(high-low)/2;
                if(ve[mid].first>worker[i]){
                    high = mid-1;
                }
                else{
                    ans = max(ans,ve[mid].second);
                    low = mid+1;
                }
            }
            res += ans;
        }
        return res;
    }
};