class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>ma;
        
        int maxFreq = 0;
        for(auto i:nums)
            ma[i]++,maxFreq = max(maxFreq,ma[i]);
        
        int sum = 0;
        
        for(auto i:ma)
            if(i.second == maxFreq)
            sum+=i.second;
        
        return sum;
        
        
    }
};