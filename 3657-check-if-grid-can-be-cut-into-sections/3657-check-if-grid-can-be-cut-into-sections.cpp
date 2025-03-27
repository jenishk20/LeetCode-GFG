class Solution {
public:
    bool check(vector<pair<int,int>>&interval){
        sort(interval.begin(),interval.end());

        int prevStart = interval[0].first;
        int prevEnd = interval[0].second;

        int cnt = 0;
        for(int i=1;i<interval.size();i++){
            int currSt = interval[i].first;
            int currEn = interval[i].second;

            if(currSt >= prevEnd){
                cnt++;
            }
            prevStart = max(currSt,prevStart);
            prevEnd = max(currEn,prevEnd);
        }
        return cnt>=2;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        
        vector<pair<int,int>>yInterval,xInterval;

        for(int i=0;i<rectangles.size();i++){
            int yStart = rectangles[i][1];
            int yEnd = rectangles[i][3];
            int xStart = rectangles[i][0];
            int xEnd = rectangles[i][2];

            xInterval.push_back({xStart,xEnd});
            yInterval.push_back({yStart,yEnd});
        }
        return check(xInterval) or check(yInterval);
    }
};