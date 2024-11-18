class Solution {
public:
    
    vector<int>processNegative(vector<int>&code,int k){
        int n = code.size();
        int r = n-1;
        int sum = 0;
        vector<int>ans;
        
        while(r>=n-k){
            sum += code[r];
            r--;
        }
        
        r = n-k;
        int l = 0;
        int total = n;
        
        while(total--){
            ans.push_back(sum);
            sum -= code[r];
            sum += code[l];
            // cout<<" "<<l<<" "<<r<<" "<<sum<<endl;
            l++;
            r++;
            
            if(r>=n){
                r = 0;
            }
        }
        return ans;
    }
    
    vector<int>processPositive(vector<int>&code,int k){
        
        int n = code.size();
        vector<int>ans(n);
        
        int l = n-1;
        int r = 0;
        int st = n-1;
        
        int sum = 0;
        while(r<k){
            sum += code[r];
            r++;
        }
        
        int total = n;
        
        r = k-1;
        while(total--){
            ans[st--] = sum;
            sum -= code[r];
            sum += code[l];
            l--;
            r--;
            if(r<0) r = n-1;
        }
        return ans;
    }
    vector<int> decrypt(vector<int>& code, int k) {
        
        int n = code.size();
        
        if(k==0) return vector<int>(n,0);
        if(k<0) return processNegative(code,abs(k));
        return processPositive(code,k);
    }
};