class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int xori = 0;

        int n = nums.size();

        for(int i=0;i<pow(2,n);i++){
            int temp = 0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)) temp ^= nums[j];
            }
            xori += temp;
        }

        return xori;
    }
};