class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
          
        vector<vector<int>>ans;
        int n = s.size();

        map<long long,vector<int>>ma;

        int i,j;
        for(i=0;i<n;i++){
            if(s[i] == '0'){
                if(ma.find(0) == ma.end())
                    ma[0] = {i,i};
                continue;
            }
            string temp = "";
            for(int j = i;j<=min(n-1,i+31);j++){
                temp += s[j];
                long long val = stoll(temp,0,2);
                if(ma.find(val) == ma.end())
                    ma[val] = {i,i+j-i};
            }
        }
       
        for(auto it : queries){
            int u = it[0];
            int v = it[1];

            int req = u^v;
            if(ma.find(req) == ma.end()){
                ans.push_back({-1,-1});
            }
            else{
                ans.push_back(ma[req]);
            }
            
        }
        return ans;
    }
};