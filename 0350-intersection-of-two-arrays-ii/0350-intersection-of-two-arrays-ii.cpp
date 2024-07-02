class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>ans;
        map<int,int>ma;
        
        for(auto it : nums1){
            ma[it]++;
        }
        
        for(auto it : nums2){
            if(ma[it]>0){
                ans.push_back(it);
                ma[it]--;
            }
        }
        return ans;
    }
};