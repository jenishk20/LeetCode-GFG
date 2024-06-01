class Solution {
public:
     int xorSum(vector<int>arr, int n)
    {
    int bits = 0;
 
    // Finding bitwise OR of all elements
    for (int i=0; i < n; ++i)
        bits |= arr[i];
 
    int ans = bits * pow(2, n-1);
 
    return ans;
    }
    int subsetXORSum(vector<int>& nums) {
        
        
        return xorSum(nums,nums.size());
       
    }
};