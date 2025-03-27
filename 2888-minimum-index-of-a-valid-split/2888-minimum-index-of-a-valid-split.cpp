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

        vector<int>sfx(n+1,0);
        for(i=n-2;i>=0;i--){
            if(nums[i+1] == overallMajority){
                sfx[i] += sfx[i+1]+1;
            }
            else{
                sfx[i] = sfx[i+1];
            }
        }

        int overallMajorityCnt = 0;
        for(i=0;i<n;i++){
            if(nums[i] == overallMajority){
                overallMajorityCnt++;

                int left = i+1;
                int right = n-i-1;
                if(overallMajorityCnt > left/2 and sfx[i]>right/2){
                    return i;
                }
            }
        }
        return -1;
    }
};