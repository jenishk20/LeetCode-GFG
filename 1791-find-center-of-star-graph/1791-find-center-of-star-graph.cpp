class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        map<int,int>ma;
        int r=edges.size();
        
        for(int i=0;i<r;i++)
        {
            ma[edges[i][0]]++;
            ma[edges[i][1]]++;
            
        }
        int ans;
        for(auto &it:ma)
        {
           // cout<<it.first<<
            if(it.second==r){
                ans=it.first;
                break;
            }
               
        }
        return ans;
    }
};