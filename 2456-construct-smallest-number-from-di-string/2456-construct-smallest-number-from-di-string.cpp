class Solution {
public:
    string smallestNumber(string pattern) {
        
        int n = pattern.size();
        int i;
        string init = "";
        int st = 1;

        for(i=0;i<=n;i++){
            init += (st + '0');
            st++;
        }  

        do{
            int j=0;
            bool be = true;
            for(j=0;j<n;j++){
                if(pattern[j] == 'I' and init[j]-'0'>init[j+1]-'0'){
                    be = false;
                }
                if(pattern[j] == 'D' and init[j]-'0'<init[j+1]-'0'){
                    be = false;
                }
            }
            if(be) return init;
            
        }while(next_permutation(init.begin(),init.end()));

        return "";
        
    }
};