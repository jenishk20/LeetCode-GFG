class Solution {
public:
    
    static bool comp(pair<string,int>p1,pair<string,int>p2){
           return p1.second>p2.second; 
        }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
         vector<string>res;
        vector<pair<string,int>>temp;
        for(int i=0;i<names.size();i++)
        {
            temp.push_back({names[i],heights[i]});
        }
        sort(temp.begin(),temp.end(),comp);
        
        for(auto i:temp)
            res.push_back(i.first);
        return res;
    }
};