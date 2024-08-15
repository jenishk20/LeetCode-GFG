class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int>ma;
        
        for(auto it : bills){
            
            int got = it;
            int refund = got - 5;
            
            if(refund == 5){
                if(ma[5]>0) ma[5]--;
                else return false;
            }
            else if(refund == 15){
                if(ma[5]>0 and ma[10]>0) {
                    ma[5]--;
                    ma[10]--;
                }
                else if(ma[5]>=3){
                    ma[5]-=3;
                }
                else{
                    return false;
                }
            }
            ma[got]++;
        }
        return true;
    }
};