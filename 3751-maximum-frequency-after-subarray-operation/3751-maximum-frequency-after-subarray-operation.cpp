class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size();
        set<int>se(nums.begin(),nums.end());

        int i,j;
        int res = 0;
        int ans = 0;

        for(i=0;i<n;i++){
            if(nums[i] == k) res++;
        }
       
        for(auto it : se){
            
            int sum = 0;
            int maxSum = 0;

            for(i=0;i<n;i++){
                if(nums[i] == k){
                    sum--;
                }
                else if(nums[i] == it){
                    sum++;
                }

                if(maxSum < sum){
                    maxSum = sum;
                }
                if(sum<0){
                    sum = 0;
                }
            }
            ans = max({ans,maxSum + res});
        }
        return ans;
    }
};