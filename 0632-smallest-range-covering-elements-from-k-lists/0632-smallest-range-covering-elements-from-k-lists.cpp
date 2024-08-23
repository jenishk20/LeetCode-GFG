class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        vector<pair<int,int>>ve;

        for(int i=0;i<nums.size();i++){
            for(auto it : nums[i]){
                ve.push_back({it,i});
            }
        }

        sort(ve.begin(),ve.end());
        map<int,int>ma;
      
        int l = 0, r = 0;
        int ans = 1e9;
        vector<int>res(2);

        while(r<ve.size()){
            ma[ve[r].second]++;

            while(ma.size() >= nums.size()){
                int currRange = ve[r].first - ve[l].first + 1;
                if(ans > currRange){
                    ans = currRange;
                    res[0] = ve[l].first;
                    res[1] = ve[r].first;
                }
                ma[ve[l].second]--;
                if(ma[ve[l].second] == 0){
                    ma.erase(ve[l].second);
                }
                l++;
            }
            r++;
        }
        return res;
    }
};