class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        stack<pair<int,int>>se;
        
        int n = temp.size();
        int i;
        vector<int>ans;
        for(i=n-1;i>=0;i--){
            if(i==n-1){
                ans.push_back(0);
            }
            else if(se.top().first>temp[i]){
                ans.push_back(abs(i-se.top().second));
            }
            else{
                while(!se.empty() and se.top().first<=temp[i]){
                    se.pop();
                }
                if(se.empty()){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(abs(i-se.top().second));
                }
            }
            se.push({temp[i],i});
        }
        reverse(ans.begin(),ans.end());
        // for(i=0;i<n;i++)
        return ans;
        
        
    }
};