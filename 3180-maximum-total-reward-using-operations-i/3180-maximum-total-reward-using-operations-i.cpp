class Solution {
public:
   
    int maxTotalReward(vector<int>& rewardValues) {
        
        bitset<100001>dp,mask,prev;
        
        sort(rewardValues.begin(),rewardValues.end());
        
        int i;
        dp[0] = 1;
        
        
        int currentMask = 0;
        
        for(auto it : rewardValues){
            while(currentMask < it) mask[currentMask++] = 1;
           
            prev = (dp&mask);
            dp|=(prev<<it);
        }
        
        int res = 1e5-1;
        
        while(!dp[res]) --res;
        
        return res;

    
       
    }
};