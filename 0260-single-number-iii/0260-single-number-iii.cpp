class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int n = nums.size();
        pair<int,int>res = {0,0};
        
        unsigned int xori = 0;
        for(auto it : nums){
            xori^=it;
        }
        
        int fxor = 0, sxor = 0;
        xori = xori & (-xori);
        
        for(auto it : nums){
            if(it&xori){
                fxor^=it;
            }
            else{
                sxor^=it;
            }
        }
        return {fxor,sxor};
    }
};