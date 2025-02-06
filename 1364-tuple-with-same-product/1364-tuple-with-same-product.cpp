class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int i,j;
        map<int,int>ma;

        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                ma[nums[i]*nums[j]]++;
            }
        }
        int ans = 0;

        for(auto it : ma){
            if(it.second >= 2){
                int canDo = (it.second * (it.second-1))/2;
                ans += canDo * 8;
            }
        }
        return ans;
    }
};