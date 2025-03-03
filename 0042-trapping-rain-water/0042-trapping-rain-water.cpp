class Solution {
public:
    int trap(vector<int>& height) {
        
        int lMax = 0, rMax = 0;
        int i = 0;
        int j = height.size()-1;

        int total = 0;

        while(i<j){
            if(height[i]<=height[j]){
                if(lMax >= height[i]){
                    total += (lMax - height[i]);
                }
                else{
                    lMax = height[i];
                }
                i++;
            }
            else{
                if(rMax >= height[j]){
                    total += (rMax - height[j]);
                }
                else{
                    rMax = height[j];
                }
                j--;
            }
        }

        return total;
    }
};