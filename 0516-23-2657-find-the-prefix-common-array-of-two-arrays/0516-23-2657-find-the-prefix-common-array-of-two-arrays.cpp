class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        int n = A.size();
        vector<int>perm(n+1,0),perm1(n+1,0);
        vector<int>ans(n,0);

        for(int i=0;i<n;i++){
            perm[A[i]]++;
            perm1[B[i]]++;
            int cnt = 0;
            for(int j=0;j<=n;j++){
                if(perm[j] and perm1[j]) cnt++;
            }
            ans[i] = cnt;
        }
        return ans;   
    }
};