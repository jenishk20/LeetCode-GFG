class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int overallMajority = 0;
        int i;
        int cnt = 0;
        
        for(i=0;i<n;i++){
            if(cnt == 0){
                overallMajority = nums[i];
                cnt++;
            }
            else if(overallMajority == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        cout<<overallMajority<<endl;
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