class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        vector<pair<int,int>>ve;
        
        for(int i=0;i<score.size();i++){
            ve.push_back({i,score[i]});
        }
        
        sort(ve.begin(),ve.end(),[](pair<int,int> a,pair<int,int> b){
           return a.second>b.second; 
        });
        
        vector<string>res(score.size());
        for(int i=0;i<ve.size();i++){
            
            if(i==0){
                res[ve[i].first] = "Gold Medal";
            }
            else if(i==1){
                res[ve[i].first] = "Silver Medal";
            }
            else if(i==2){
                res[ve[i].first] = "Bronze Medal";
            }
            else{
                res[ve[i].first] = to_string(i+1);
            }
        }
        return res;
        
    }
};