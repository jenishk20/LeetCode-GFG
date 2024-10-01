class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        
        long long st = 1;
        int n = operations.size();
        
        if(k == 1) return 'a';
        
        int opType;
        long long toFind = 0;
        
        
        for(int i=0;i<n;i++){
            st *= 2;
            
            if(st >= k){
                toFind = k - st/2;
                opType = operations[i];
                break;
            }
        }
        
        cout<<toFind<<" "<<opType<<endl;
        char ch = kthCharacter(toFind,operations);
        
        if(opType == 0) return ch;
        
        return ch == 'z' ? 'a' :  ch + 1;
        
        
        
    }
};