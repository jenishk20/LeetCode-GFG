class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        
        int low = 0;
        int high = n*n;
        int ans = 0;

        while(low<=high){
            int mid = (low + high)/2;

            if(mid * w <= maxWeight){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
        
    }
};