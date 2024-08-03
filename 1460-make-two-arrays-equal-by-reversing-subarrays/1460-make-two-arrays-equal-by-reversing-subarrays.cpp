class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int>ma;
        for(auto it : arr) ma[it]++;

        for(auto it : target) {
            if(ma.find(it) == ma.end()) return false;
            ma[it]--;
            if(ma[it] == 0) ma.erase(it);
        }
        
        return ma.empty();
    }
};