class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
   
        
        map<int,int>ma;
        for(auto it : arr){
            if(ma.find(it*2)!=ma.end() or (it%2==0 and ma.count(it/2))){
                return true;
            }
            ma[it]++;
        }
        return false;
    }
};