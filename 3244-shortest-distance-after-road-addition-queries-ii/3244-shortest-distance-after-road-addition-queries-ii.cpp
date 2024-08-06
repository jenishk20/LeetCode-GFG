class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;

        unordered_map<int,int>ma;
        vector<int>reachingTo(n+1,-1);

        int shortestDis = n-1;

        int firstQS = queries[0][0];
        int firstQD = queries[0][1];

        for(int i=firstQS+1;i<firstQD;i++){
            ma[i] = true;
        }

        shortestDis -= (firstQD - firstQS - 1);
        reachingTo[firstQS] = firstQD;
        ans.push_back(shortestDis);
        for(int i=1;i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];

            if(ma.find(u)!=ma.end()){
                ans.push_back(shortestDis);
            }
            else{
    
                int cnt = 0;
                int st = u;

                while(u < v){

                    if(u!=st) ma[u] = 1;
                    if(reachingTo[u] != -1){
                        u = reachingTo[u];
                    }
                    else{
                        u++;
                    }
                    cnt++;
                    
                }
                shortestDis -= (cnt-1);
                reachingTo[queries[i][0]] = queries[i][1];
                ans.push_back(shortestDis);
            }
        }
        return ans;
    }
};