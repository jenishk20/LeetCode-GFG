class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int cntLess = 0,cntEq = 0;
        vector<int>res(n,0);

        int i=0;
        int j=n-1;
        int aSt = 0;
        int aEn = n-1;
        while(i<n and j>=0){
            if(nums[i]<pivot){
                res[aSt++] = nums[i];
            }
            if(nums[j]>pivot){
                res[aEn--] = nums[j];
            }
            i++;
            j--;
        }
      
        while(aSt<=aEn){
            res[aSt++] = pivot;
        }
        return res;

    }
};