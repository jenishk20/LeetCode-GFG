class Solution {
public:
    int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int>temp;
        
        int sum =0 ;
        int i,j;
        
        for(i=0;i<n;i++){
            sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                temp.push_back(sum);
            }
        }
        
        sort(temp.begin(),temp.end());
        
        int ans = 0;
        int k = temp.size();
        right = min(right,k);
        
        for(int i=left-1;i<right;i++){
            ans =(ans +  temp[i]) % mod;
        }
        return ans;
    }
};