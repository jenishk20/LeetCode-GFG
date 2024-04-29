class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int n = nums.size();
        int cnt = 0;
        
        for(int i=0;i<=31;i++){
            
            int xori = (k>>i)&1;
            
            for(int j=0;j<n;j++){
                
                xori ^= ((nums[j]>>i)&1);    
            }
            
            if(xori != 0) cnt++;
            cout<<xori<<endl;
        }
        return cnt;
    }
};