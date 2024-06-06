class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int k) {
          
        int n = hand.size();
        
        if(n%k!=0) return false;
        
        sort(hand.begin(),hand.end());

        map<int,int>ma;
        for(auto it : hand){
            ma[it]++;
        }
        
        for(auto it : hand){
            
            if(ma[it]>0){
                
                int kk = ma[it];
                int curr = it+1;
                int j=1;
                
                while(j<k){
                    if(ma[curr]<kk){
                        return false;
                    }
                    ma[curr]-=kk;
                    curr++;
                    j++;
                }
                ma[it] = 0;
            }
            
        }
        return true;
    }
};