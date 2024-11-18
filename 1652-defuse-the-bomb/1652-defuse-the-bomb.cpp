class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
        int n = code.size();
        
        if(k==0) return vector<int>(n,0);
        
        int start = 1;
        int end = k;
        
        vector<int>res(n,0);
        int sum = 0;
        
        if(k<0){
            k*=-1;
            start = n-k;
            end = n-1;
        }
        
        for(int i = start;i<=end;i++){
            sum += code[i];
        }
    
        end = (end+1)%n;
        
        for(int i=0;i<n;i++){
            res[i] = sum;
            sum -= code[start];
            sum += code[end];
            start = (start + 1) %n;
            end = (end+1)%n;
        }
        
        return res;
    }
};