class Solution {

private:
    map<char,vector<int>>positionsOfChars;
    int dp[201][201];
    
    int getMinSpells(int ringPointer,int keyPointer,int n,int m,string &ring,string &key){
        
        if(keyPointer>=m || ringPointer>=n) return 0;
        
        // Check if sub-problem is already solved
        
        if(dp[ringPointer][keyPointer]!=-1) return dp[ringPointer][keyPointer];
        
        // Iterate through each of the occurences of ring[ringPointer]
        
        int minSteps = INT_MAX;
        
        for(auto idx : positionsOfChars[key[keyPointer]]){
            
            int clockWiseDist = abs(idx-ringPointer);
            int antiClockWiseDist = n-abs(idx-ringPointer);
            

            int minPossDist = min(clockWiseDist,antiClockWiseDist);
            
            int stepsTaken =  minPossDist + 
                getMinSpells(idx,keyPointer+1,n,m,ring,key) +1;
            
            minSteps = min(minSteps,stepsTaken);
            
            
        }
        
        return dp[ringPointer][keyPointer] = minSteps;
    }
    
public:
    int findRotateSteps(string ring, string key) {
        
        int n = ring.size();
        int m = key.size();
        
        for(int i=0;i<ring.size();i++){
            positionsOfChars[ring[i]].push_back(i);
        }
        
        int ringPointer=0,keyPointer=0;
        
        memset(dp,-1,sizeof dp);
        
        return getMinSpells(ringPointer,keyPointer,n,m,ring,key);
    }
};