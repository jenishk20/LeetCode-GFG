class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
              
        vector<int>ans;
        int n = nums.size();
        map<int,int>ma;
        int i,j;

        for(i=0;i<n;i++){
            for(int j=0;j<32;j++){
                if(nums[i] & (1<<j)){
                    ma[j]++;
                }
            }
        }

        for(i=n-1;i>=0;i--){
            int xori = 0;
            for(j=0;j<maximumBit;j++){
                if(ma[j]%2==0){
                    xori |= (1<<j);
                }
            }
            ans.push_back(xori);
            for(j=0;j<31;j++){
                if(nums[i] & (1<<j)){
                    ma[j]--;
                }
            }
        }
        return ans;

    }
};