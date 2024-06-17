class Solution {
public:
    
    bool check(int x){
        
        cout<<"checking "<<x<<endl;
        double k = sqrt(x);
        
        return k*k == x;
    }
    bool judgeSquareSum(int c) {
        
       
        
        int low = 0;
        int high = sqrt(c);
        
        while(low<=high){
            
            if(low*1ll*low + high*1ll*high == c){
                return true;
            }
            
            else if(low*1ll*low + high*1ll*high > c){
                high--;
            }
            
            else{
                low++;
            }
        }
        
        return false;
        
        
    }
};