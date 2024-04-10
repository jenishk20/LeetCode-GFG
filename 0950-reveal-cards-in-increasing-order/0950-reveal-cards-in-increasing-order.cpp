class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        int n=deck.size();
        deque<int>dq;
        sort(deck.begin(),deck.end());
        vector<int>ans(n);
        
        int i;
        for(i=0;i<n;i++)
            dq.push_back(i);
        i=0;
        int flip=0;
        while(!dq.empty())
        {
            
            if(flip==0)
            {
                ans[dq.front()]=deck[i++];
                dq.pop_front();
            }
            else
            {
                dq.push_back(dq.front());
                dq.pop_front();
                
            }
            flip^=1;
        }
        return ans;
    }
};