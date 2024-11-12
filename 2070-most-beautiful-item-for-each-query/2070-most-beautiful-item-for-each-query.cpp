class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
                sort(items.begin(),items.end());
        vector<int>res;
        int n = items.size();
        int maxSeen = items[0][1];

        for(int i=1;i<n;i++){
            maxSeen = max(maxSeen,items[i][1]);
            items[i][1] = maxSeen;
        }   

        for(auto it : queries){
            int price = it;
            int low = 0;
            int high = items.size()-1;
            int ans = -1;
            while(low<=high){
                int mid = (low+high)/2;

                if(items[mid][0]<=price){
                    ans = mid;
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            if(ans != -1)
                res.push_back(items[ans][1]);
            else 
                res.push_back(0);
        }
        return res;
    }
};