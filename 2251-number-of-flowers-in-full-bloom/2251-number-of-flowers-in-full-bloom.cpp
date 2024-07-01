class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        int n = flowers.size();
        int m = people.size();
        int i;
        
        vector<pair<int,int>>temp;
        vector<int>ans(m);
        
        for(i=0;i<m;i++){
            temp.push_back({people[i],i});
        }
        
        vector<int>result(m+1,0);

        
        sort(temp.begin(),temp.end());
        
        for(auto it : flowers){
            int st = it[0];
            int en = it[1];
                
            pair<int,int>curr = {st,INT_MIN};
            pair<int,int>curr1 = {en+1,INT_MIN};
            
            int k = lower_bound(temp.begin(),temp.end(),curr) - temp.begin();
            int p = lower_bound(temp.begin(),temp.end(),curr1) - temp.begin();
          
            
            result[k]+=1;
            result[p]-=1;
            
        }
        
        for(i=1;i<=m;i++){
            
            result[i]+=result[i-1];
            cout<<result[i]<<" ";
        }
        cout<<endl;
        
        for(i=0;i<m;i++){
           ans[temp[i].second] = result[i]; 
        }
        
        return ans;
    }
};