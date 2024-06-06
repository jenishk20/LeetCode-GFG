class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n = hand.size();
        
        if(n%groupSize!=0) return false;
        
        sort(hand.begin(),hand.end());

        map<int,int>ma;
        for(auto it : hand){
            ma[it]++;
        }
        
        for(auto it : hand){
            
            if(ma[it]>0){
                int k = ma[it];
                int curr = it+1;
                int j=1;
                while(j<groupSize){
                    if(ma[curr]<k){
                        return false;
                    }
                    ma[curr]-=k;
                    curr++;
                    j++;
                }
                ma[it] = 0;
            }
            
        }
        return true;
    }
};