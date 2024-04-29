class Solution {
public:
    
    bool check(int mid,vector<int>&nums){
        
        int n = nums.size();
        
        long long subarrays = n*1ll*(n+1)/2;
        int left = 0;
        int right = 0;
        
        unordered_map<int,int>ma;
        
        long long cnt = 0;
        
        while(right<n){
            ma[nums[right]]++;
            
            while(ma.size()>mid){
                
                ma[nums[left]]--;
                if(ma[nums[left]]==0) ma.erase(nums[left]);
                left++;
            }
            
            cnt += (right-left+1);
            right++;
        }
        
        return cnt>=ceil((double)subarrays/2);
        
    }
    int medianOfUniquenessArray(vector<int>& nums) {
        
        set<int>se;
        
        for(auto it : nums)
            se.insert(it);
        
        int low = 1;
        int high = se.size();
        
        int ans = 0;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            if(check(mid,nums)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};