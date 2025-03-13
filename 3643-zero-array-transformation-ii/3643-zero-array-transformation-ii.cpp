class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();

        vector<int>pfxArray(n+1,0);
        int currSum = 0;
        int k = 0;

        for(int i=0;i<n;i++){

            int currentNum = nums[i];
            while(currSum + pfxArray[i] < currentNum){
                k++;
                if(k>queries.size()) return -1;

                int u = queries[k-1][0];
                int v = queries[k-1][1];
                int wt = queries[k-1][2];

                if(i<=v){
                    pfxArray[max(u,i)] += wt;
                    pfxArray[v+1] -= wt;
                }
            }
            currSum += pfxArray[i];
        }
        return k;
    }
};