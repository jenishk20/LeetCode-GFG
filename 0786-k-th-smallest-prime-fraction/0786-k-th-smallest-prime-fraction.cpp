class Solution {
public:
    
    vector<int> findNoSmallerThanMid(double mid,vector<int>&arr,int k){
        
        int i=0,j;
        int n = arr.size();
        
        int cnt =0;
        int num = arr[0];
        int den = arr[n-1];
        
        for(j=1;j<n;j++){
            
            while(i<j and arr[i] <= mid*arr[j]){
                i++;
            }
            
            cnt+=i;
            
            if(i-1>=0 && arr[i-1]*den>num*arr[j]){
                num = arr[i-1];
                den = arr[j];
            }
        }
        return {cnt,num,den};
        
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        double low = 0;
        double high = 1;
        
        while(low<high){
            
            double mid = (low+high)/2;
            
            int cnt = 0;
            
            vector<int>res = findNoSmallerThanMid(mid,arr,k);
    
            if(res[0] == k){
                return {res[1],res[2]};
            }
            if(res[0]<k){
                low = mid;
            }
            else{
                high = mid;
            }
            
        }
        return {};
    }
};