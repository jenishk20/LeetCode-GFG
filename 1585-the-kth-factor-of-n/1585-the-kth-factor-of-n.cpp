class Solution {
public:
    int kthFactor(int n, int k) {
        
        int i;
        for(i=1;i<sqrt(n);i++){
            if(n%i==0 and --k==0) return i;
        }
        cout<<k<<endl;
        for(i=(int)sqrt(n);i>=1;i--){
            if(n%(n/i) == 0 and --k == 0) return n/i;
        }
        return -1;
    }
};