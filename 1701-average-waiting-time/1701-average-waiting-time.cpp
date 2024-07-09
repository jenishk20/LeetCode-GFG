class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
                
        long long sum = 0;
        int time = customers[0][0];

        for(auto it : customers){
            
            if(it[0]>time){
                time = it[0];
            }
            int currTime = it[1];
            time+=currTime;
            sum+=(time-it[0]);
        }

        double ans = (double)sum/(customers.size());
        return ans;
    
    }
};