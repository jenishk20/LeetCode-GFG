class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int maxi = *max_element(candies.begin(),candies.end());
        vector<bool>ans;

        for(auto it : candies){
            ans.push_back(it+extraCandies >= maxi);
        }
        return ans;
    }
};