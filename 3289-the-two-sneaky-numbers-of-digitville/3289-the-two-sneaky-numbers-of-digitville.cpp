class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        
        int n = nums.size();
        
        int xorOfFullArray = 0;
        int xorOfActualEle = 0;
        int xorOfTwoEle = 0;
        
        for(int i=0;i<n;i++){
            xorOfFullArray ^= nums[i];
        }
        
        for(int i=0;i<n-2;i++){
            xorOfActualEle ^= i;
        }
        
        xorOfTwoEle = xorOfActualEle ^ xorOfFullArray;
        
        int fNo = 0, sNo = 0;
        int leftMostSet = 0;
        
        for(int i=31;i>=0;i--){
            if(xorOfTwoEle & (1<<i)){
                leftMostSet = 1<<i;
                break;
            }
        }
        
        for(int i=0;i<n-2;i++){
            if(i&leftMostSet){
                fNo ^= i;
            }
            else{
                sNo ^= i;
            }
        }
        
        
        for(int i=0;i<n;i++){
            if(nums[i]&leftMostSet){
                fNo ^= nums[i];
            }
            else{
                sNo ^= nums[i];
            }
        }
    
        return {fNo,sNo};
    }
};