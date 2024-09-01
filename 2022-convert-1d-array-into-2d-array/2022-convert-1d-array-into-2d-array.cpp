class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int ptr = 0;
        int i=0,j=0;

        if(n*m != original.size()) return {};

        vector<vector<int>>ans(m,vector<int>(n,0));

        while(ptr < m*n){
            ans[i][j++] = original[ptr];
            if(j>n-1){
                j=0;
                i++;
            }
            ptr++; 
        }
        return ans;
    }
};