class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>se;

        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]<0){
                while(!se.empty() and se.top()>0 and se.top()<abs(asteroids[i])){
                    se.pop();
                }
                if(!se.empty() and se.top()>abs(asteroids[i])) continue;
                if(!se.empty() and se.top() == abs(asteroids[i])){
                    se.pop();
                    continue;
                }
            }
            se.push(asteroids[i]);
        }

        while(!se.empty()){
            ans.push_back(se.top());
            se.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};