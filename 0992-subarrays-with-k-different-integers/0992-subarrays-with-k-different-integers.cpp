class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int n = nums.size();
        map<int,int>ma;
        
        int l = 0,m = 0, r = 0;
        int count = 0;
        
        while(r<n){
            
            ma[nums[r]]++;
            
            cout<<ma.size()<<" "<<ma[nums[l]]<<endl;
            while(ma.size()>k){
                ma[nums[m]]--;
                if(ma[nums[m]]==0) ma.erase(nums[m]);
                m++;
                l = m;
            }
            
            while(ma[nums[m]]>1){
                ma[nums[m]]--;
                m++;
            }
            
            if(ma.size() == k){
                count+=(m-l+1);
            }
            
            cout<<l<<" "<<m<<" "<<r<<" "<<count<<endl;
    
            r++;
        }
        
        return count;
    }
};