class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        // sort(nums.begin(),nums.end());
        int i=0;
        int j=0;
        set<vector<int>>res;
        set<int>dups;
        map<int,int>done;

        for(i=0;i<n;i++){
            if(!dups.count(nums[i])){
                dups.insert(nums[i]);
                for(j=i+1;j<n;j++){
                    int req = -nums[i]-nums[j];
                    if(done.find(req) != done.end() and done[req] == i){
                        vector<int>tt = {nums[i],nums[j],req};
                        sort(tt.begin(),tt.end());
                        res.insert(tt);
                    }
                    done[nums[j]] = i;
                }
            }
        }
        return vector<vector<int>>(begin(res),end(res));
    }
};