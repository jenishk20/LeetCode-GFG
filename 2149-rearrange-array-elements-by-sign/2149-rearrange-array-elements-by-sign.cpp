class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        deque<int>pos,neg;
        for(auto i:nums){
            if(i>=0){
                pos.push_back(i);
            }
            else{
                neg.push_back(i);
            }
        }
        
        int n = nums.size();
        int i=0,j=0;
        
        bool turn = 1;
        while(i<n/2 and j<n/2){
            
            if(turn){
                ans.push_back(pos.front());
                pos.pop_front();
                i++;
            }
            else{
                ans.push_back(neg.front());
                neg.pop_front();
                j++;
            }
            turn^=1;
        }
        ans.push_back(neg.front());
        
        return ans;
    }
};