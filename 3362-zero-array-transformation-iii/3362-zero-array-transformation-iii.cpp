class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        
        sort(queries.begin(),queries.end());
        
        priority_queue<int>available;
        priority_queue<int,vector<int>,greater<int>>active;
        
        int n = nums.size();
        int j = 0;
        int req = 0;
      
    
        for(int i=0;i<n;i++){
            
            while(j<queries.size() and queries[j][0] == i){
                available.push(queries[j][1]);
                j++;
            }
            
            nums[i] -= active.size();
            
            while(nums[i]>0 and !available.empty() and available.top()>=i){
                req++;
                nums[i]--;
                active.push(available.top());
                available.pop();
            }
            
            if(nums[i]>0) return -1;
            
            while(!active.empty() and active.top() == i){
                active.pop();
            }
        }
        
        return queries.size() - req;
        
    }
};