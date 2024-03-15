class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        int i;
        int p1=1;
        int p2=1;
        vector<int>prd(n,1);
        for(i=0;i<n;i++)
        {
            prd[i]*=p1;
            p1*=nums[i];
            int j=n-1-i;
            prd[j]*=p2;
            p2*=nums[j];
        }
      
//         p=1;
//         for(i=n-1;i>=0;i--)
//         {
//             prd[i]*=p;
//             p*=nums[i];
//         }
        
//         for(i=0;i<n;i++)
//         {
//             cout<<prd[i]<<" ";
//         }
        return prd;
    }
};