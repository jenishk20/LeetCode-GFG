class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        if(is_sorted(nums.begin(),nums.end())){
            return true;
        }

        int i;
        for(i=0;i<n;i++){
            int curr = __builtin_popcount(nums[i]);
            int st = i;
            while(i+1<n and curr == __builtin_popcount(nums[i+1])){
                i++;
            }
            int en = i;
            sort(nums.begin()+st,nums.begin()+en+1);
        }

        if(is_sorted(nums.begin(),nums.end())){
            return true;
        }
        return false;

    }
};