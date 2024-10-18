class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxiOR = 0;
        for(auto it : nums){
            maxiOR |= it;
        }
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<(1<<n);i++){
            vector<int>tmp;
            int ori = 0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    ori |= nums[j];
                }
            }
            if(ori == maxiOR) cnt++;
        }
        return cnt;
    }
};