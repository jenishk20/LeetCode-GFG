class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n = nums.size();
        int currWindowFlips = 0;
        
        int i,j;
        int res =0 ;
        
        for(i=0;i<n;i++){
            
            if(i-k>=0 and nums[i-k]==2) currWindowFlips--;
            
            if((nums[i]+currWindowFlips)%2==0){
                
                if(i+k>n) return -1;
                
                nums[i] = 2;
                currWindowFlips++;
                res++;
            }
        }
        return res;
    }
};