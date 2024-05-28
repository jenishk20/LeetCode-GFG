class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int n = s.size();
        vector<int>arr(n,0);
        int i;
        
        for(i=0;i<n;i++){
            arr[i] = abs(s[i]-t[i]);
        }
        
        for(i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        
        i=0;
        int j = 0;
        int ans = 0;
        int currSum = 0;
        
        while(j<n){
            
            currSum+=arr[j];
            
            if(currSum<=maxCost){
                ans = max(ans,j-i+1);
            }
            if(currSum>maxCost){
               currSum-=arr[i];
               i++;
            }
            
            j++;
        }
        return ans;
    }
};