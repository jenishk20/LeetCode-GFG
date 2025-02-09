class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long totalPairs = (n*1ll*(n-1))/2;
        map<int,int>ma;
        long long cnt = 0;

        for(int i=n-1;i>=0;i--){
            if(ma.find(nums[i]-i) != ma.end()){
                cnt += ma[-i+nums[i]];
                ma[nums[i]-i]++;
            }
            else{
                ma[-i+nums[i]]++;
            }
            
        }
        return totalPairs - cnt;
    }
};