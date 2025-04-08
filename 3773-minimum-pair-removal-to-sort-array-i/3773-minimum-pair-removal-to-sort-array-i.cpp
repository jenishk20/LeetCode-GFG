class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
       
        int cnt = 0;

        while(1){
            if(is_sorted(nums.begin(),nums.end())){
                return cnt;
            }
            int n = nums.size();
            vector<pair<int,int>>pairSums;
            for(int i=0;i<n-1;i++){
                pairSums.push_back({i,nums[i]+nums[i+1]});
            }

            sort(pairSums.begin(),pairSums.end(),[](pair<int,int>&a,pair<int,int>&b){
                if(a.second == b.second) return a.first < b.first;
                return a.second < b.second;
            });

            int minSumIdx = pairSums[0].first;
            int sum = pairSums[0].second;

            vector<int>temp;
            
            for(int i=0;i<n;i++){
                if(i == minSumIdx){
                    temp.push_back(sum);
                    i++;
                }
                else{
                    temp.push_back(nums[i]);
                }
            }
            nums = temp;
            cnt++;
        }

        return cnt;
    }
};