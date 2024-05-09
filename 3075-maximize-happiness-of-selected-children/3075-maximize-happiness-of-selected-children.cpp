class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        long long res = 0;
        sort(happiness.begin(),happiness.end());
        
        int st = 0;
        for(int i=happiness.size()-1;i>=0 && k;i--){
            
            res += (happiness[i]-st>0 ? happiness[i]-st:0);
            k--;
            st++;
        }
        return res;
    }
};