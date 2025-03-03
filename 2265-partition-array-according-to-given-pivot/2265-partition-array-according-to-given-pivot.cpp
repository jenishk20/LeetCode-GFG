class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int cntLess = 0,cntEq = 0;
        vector<int>res(n,0);

        int i;
        for(i=0;i<n;i++){
            if(nums[i]<pivot) cntLess++;
            else if(nums[i] == pivot) cntEq++;
        }

        int st = 0;
        int mid = cntLess;
        int next = cntLess + cntEq;

        for(i=0;i<n;i++){
            if(nums[i]<pivot) res[st++] = nums[i];
            else if(nums[i] == pivot) res[mid++] = nums[i];
            else res[next++] = nums[i];
        }
        return res;
    }
};