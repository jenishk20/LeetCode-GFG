class Solution {
public:
    void solve(string &tiles,string &curr,unordered_set<string>&se,vector<int>&used){
        se.insert(curr);

        for(int i=0;i<tiles.size();i++){
            if(used[i] == 0){
                curr += tiles[i];
                used[i] = 1;
                solve(tiles,curr,se,used);
                used[i] = 0;
                curr.pop_back();
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<int>used(n+1,0);

        unordered_set<string>se;
        string curr = "";
        solve(tiles,curr,se,used);

        return se.size()-1;
    }
};