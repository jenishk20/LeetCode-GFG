class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int>freq(k,0);
        
        for(int i=0;i<n;i++){
            int rem = arr[i]%k;
            
            if(rem < 0) rem += k;
            
            freq[rem]++;
        }
        
        for(int i=1;i<=k/2;i++){
            if(freq[i] != freq[k-i]) return false;
        }
        
        return freq[0]%2 == 0;
        
    }
};