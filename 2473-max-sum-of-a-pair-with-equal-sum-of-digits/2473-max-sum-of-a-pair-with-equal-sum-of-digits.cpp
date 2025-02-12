class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>>ma;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int sum = 0;
            int ele = nums[i];
            while(nums[i]){
                sum += nums[i]%10;
                nums[i]/=10;
            }
            ma[sum].push_back(ele);
        }  

        

        int maxi = -1;
        for(auto it : ma){
            if(it.second.size()>=2){
               sort(it.second.begin(),it.second.end());
               maxi = max(maxi,it.second[it.second.size()-1] + it.second[it.second.size()-2]);
            }
        }

        return maxi;
    }
};