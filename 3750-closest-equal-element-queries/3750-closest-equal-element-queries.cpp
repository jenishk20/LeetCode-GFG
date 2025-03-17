class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        int n = nums.size();
        map<int,vector<int>>ma;
        vector<int>res;

        int i,j;

        for(i=0;i<n;i++){
            ma[nums[i]].push_back(i);
        }

        for(auto &it : queries){
            vector<int>&indices = ma[nums[it]];
            int ans = 1e9;
            int sz = indices.size();

            if(sz == 1){
                res.push_back(-1);
            }
            else{
                int idx = lower_bound(indices.begin(),indices.end(),it) - indices.begin();
                if(idx + 1 < sz){
                    ans = min({ans,indices[idx+1] - it });
                }
                else{
                    ans = min({ans,n - it + indices[0]});
                }

                if(idx-1>=0){
                    ans = min({ans,-indices[idx-1] + it });
                }
                else{
                    ans = min({ans, it + n - indices[sz-1]});
                }
                res.push_back(ans);
            }
        }

        // for(auto &it : queries){
        //     int elem = nums[it];
        //     auto vec = ma[elem];
        //     if(vec.size() == 1){
        //         res[i++] = -1;
        //     }
        //     else{
        //         int ans = 1e9;
        //         int firstOccurence = lower_bound(vec.begin(),vec.end(),it) - vec.begin();
        //         if(firstOccurence+1<vec.size()){
        //             ans = min({ans,vec[firstOccurence+1] - it});
        //         }
        //         else{
        //             ans = min({ans,n-it+vec[0]});
        //         }
        //         if(firstOccurence-1>=0){
        //             ans = min({ans,it - vec[firstOccurence-1]});
        //         }
        //         else{
        //             ans = min({ans,it  + n - vec[vec.size()-1]});
        //         }
        //         res[i++] = ans;
        //     }
        // }
        return res;
    }
};