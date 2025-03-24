class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        int n = meetings.size();
        sort(meetings.begin(),meetings.end());

        int cnt = 0;
        int prevSt = 0;
        int prevEn = 0;

        for(int i=0;i<n;i++){
            int currSt = meetings[i][0];
            int currEn = meetings[i][1];
            
            if(currSt > prevEn){
                cnt += (currSt - prevEn-1);
            }
            cout<<prevSt<<" "<<prevEn<<" "<<currSt<<" "<<currEn<<" "<<cnt<<endl;

            prevSt = currSt;
            prevEn = max(prevEn,currEn);
        }
        return cnt + days - prevEn;
    }
};