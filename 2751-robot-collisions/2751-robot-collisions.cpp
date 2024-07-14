class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& h, string dir) {
     
        vector<int>ans;

        map<int,int>ma;

        int n = positions.size();

        int i;

        for(i=0;i<n;i++){
            ma[positions[i]] = i;
        }

        sort(positions.begin(),positions.end());

        stack<int>positionTrack;

        for(i=0;i<n;i++){
            
            int currPosition = positions[i];
            int idxInInitialArray = ma[currPosition];
            int healthOfCurrentRobot = h[idxInInitialArray];
            char directionOfCurrentRobot = dir[idxInInitialArray];
            
            if(directionOfCurrentRobot == 'R'){
                positionTrack.push(idxInInitialArray);
            }
            else{

                while(!positionTrack.empty() and dir[positionTrack.top()] == 'R'
                  and h[idxInInitialArray]){

                    int previousRobotIdx = positionTrack.top();
                    positionTrack.pop();

                    if(h[idxInInitialArray]  == h[previousRobotIdx]){
                        h[previousRobotIdx] = 0;
                        h[idxInInitialArray] = 0;
                    }
                    else if(h[idxInInitialArray] > h[previousRobotIdx]){
                        h[idxInInitialArray]--;
                        h[previousRobotIdx] = 0;
                    }
                    else{
                        h[previousRobotIdx]--;
                        h[idxInInitialArray] = 0;
                        positionTrack.push(previousRobotIdx);
                    }
                }
            }
        }

        for(auto it : h){
            if(it>0)
            ans.push_back(it);
        }
        return ans;



    }
};