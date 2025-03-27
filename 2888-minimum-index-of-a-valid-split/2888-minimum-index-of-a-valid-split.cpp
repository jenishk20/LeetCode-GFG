class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int>ma;

        int n = nums.size();
        int overallMajority = -1;
        int i;

        for(auto it : nums){
            ma[it]++;
            if(ma[it] > n/2){
                overallMajority = it;
            }
        }

        int totalMajorityCnt = 0;
        for(i=0;i<n;i++){
            if(nums[i] == overallMajority) totalMajorityCnt++;
        }

        int currentMajorityCnt = 0;
        for(i=0;i<n;i++){
            if(nums[i] == overallMajority){
                currentMajorityCnt++;
                int left = i+1;
                int right = n-i-1;
                if(currentMajorityCnt > left/2 and totalMajorityCnt - currentMajorityCnt > right/2){
                    return i;
                }
            }
        }
        return -1;
    }
};