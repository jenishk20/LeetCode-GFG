class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        priority_queue<pair<int,int>>pqmax;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pqmin;

        int n = nums.size();
        int i=0;
        int j=0;
        int ans = 0;
        while(j<n){
    
            pqmin.push({nums[j],j});
            pqmax.push({nums[j],j});

            while(pqmin.top().second<i) pqmin.pop();
            while(pqmax.top().second<i) pqmax.pop();
            if(pqmax.top().first-pqmin.top().first<=limit){
                ans = max(ans,j-i+1);
            }
            else{
                i++;
            }

            j++;
            
        }
        return ans;

    }
};