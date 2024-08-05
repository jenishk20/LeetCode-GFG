class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>ma;
        
        for(auto it : arr){
            ma[it]++;
        }
        
        for(auto it : arr){
            if(ma[it] == 1 and k == 1){
                return it;
            }
            else if(ma[it] == 1){
                k--;
            }
        }
        return "";
    }
};