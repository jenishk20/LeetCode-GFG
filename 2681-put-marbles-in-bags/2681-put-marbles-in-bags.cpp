class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long ans = 0;

        int n = weights.size();
        int i;
        vector<int>pairSum(n-1,0);

        for(i=0;i<n-1;i++){
            pairSum[i] = weights[i] + weights[i+1];
        }

        sort(pairSum.begin(),pairSum.end());

        
        long long s1 = 0;
        long long s2 = 0;

        for(i=0;i<k-1;i++){
            s1 += pairSum[i];
        }

        for(i=n-2;i>=n-k;i--){
            s2 += pairSum[i];
        }

        // cout<<s1<<" "<<s2<<endl;

        return s2-s1;
    }
};