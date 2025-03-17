class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        
        vector<int>res;

        int n = nums.size();
        vector<int>dis(n,1e9);

        int i,j;
        map<int,int>seen;

        for(i=0;i<2*n;i++){
            if(seen.count(nums[i%n])){
                dis[i%n] = min(dis[i%n],(i) - seen[nums[i%n]]);
            }
            seen[nums[i%n]] = i%n;
        }

        seen.clear();

        cout<<seen.size()<<endl;

        for(i=0;i<n;i++){
            cout<<dis[i]<<" ";
        }
        cout<<endl;

        for(i=2*n-1;i>=0;i--){
            if(seen.count(nums[i%n])){
                dis[i%n] = min(dis[i%n],-(i) + seen[nums[i%n]]);
            }
            seen[nums[i%n]] = i;
        }

        for(i=0;i<n;i++){
            cout<<dis[i]<<" ";
        }
        cout<<endl;

        for(auto it : queries){
            if(dis[it]>=n) res.push_back(-1);
            else res.push_back(dis[it]);
        }


        return res;
    }
};