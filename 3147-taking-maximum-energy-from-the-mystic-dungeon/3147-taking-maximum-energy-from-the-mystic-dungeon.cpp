// class Solution {

// private:
//     int recur(int st,vector<int>&energy,int k){
        
//         if(st>=energy.size()) return 0;
        
//         return energy[st] + recur(st+k,energy,k);
//     }
      
// public:

//     int maximumEnergy(vector<int>& energy, int k) {
        
//         int n = energy.size();

//         for(i=0;i<n;i++){
//             ans = max(ans,recur(i,energy,k));
//         }
        
//         return ans;  
//     }
// };


class Solution {

private:
    int dp[100001];
    int recur(int st,vector<int>&energy,int k){
        
        if(st>=energy.size()) return 0;
        
        if(dp[st]!=-1) return dp[st];
        
        return dp[st] = energy[st] + recur(st+k,energy,k);
    }
      
public:

    int maximumEnergy(vector<int>& energy, int k) {
        
        int n = energy.size();
        memset(dp,-1,sizeof dp);
        
        int ans = -1e5;
        
        for(int i=0;i<n;i++){
            ans = max(ans,recur(i,energy,k));
        }
        
        return ans;  
    }
};