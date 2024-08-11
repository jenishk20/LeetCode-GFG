class Solution {
public:
    unordered_map<string,vector<string>>ma;
    int n = 0;
    vector<string>route;

    void dfs(string currCity,vector<string>&tempRoute){

        tempRoute.push_back(currCity);

        // cout<<currCity<<endl;
        if(tempRoute.size() == n + 1) {
            
            route = tempRoute;
            return;
        }

        vector<string>&neighBours = ma[currCity];

        for(int i=0;route.empty() and i<neighBours.size();i++){
            
            string toAirport = neighBours[i];
            neighBours.erase(neighBours.begin()+i);
            dfs(toAirport, tempRoute);
            neighBours.insert(neighBours.begin()+i, toAirport);            
        }
        tempRoute.pop_back();
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        n = tickets.size();

        if(n==0) return route;

        for(auto it : tickets){
            string u = it[0];
            string v = it[1];

            ma[u].push_back(v);
        }

        for(auto &it : ma){
            sort(it.second.begin(),it.second.end());
        }

        stack<string>se;
        

        se.push("JFK");

        while(!se.empty()){

            string currCity = se.top();
            
            if(ma[currCity].size() == 0){
                route.push_back(currCity);
                se.pop();
            }
            else{
                auto dst = ma[currCity].begin();
                se.push(*dst);
                ma[currCity].erase(dst);
            }
        }
        reverse(route.begin(),route.end());
        return route;
    }
};