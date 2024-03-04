class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>res(n);
        
        int l = 0;
        int r = n-1;
        
        int st = n-1;
        
        while(l<=r){
            
            int p1 = abs(nums[l]);
            int p2 = abs(nums[r]);
            
            if(p1>p2){
                res[st--] = p1*p1;
                l++;
            }
            else{
                res[st--] = p2*p2;
                r--;
            }
        }
        
        return res;
    }
};