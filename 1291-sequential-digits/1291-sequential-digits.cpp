class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>res;
            
        queue<int>q;
        for(int i=1;i<=9;i++){
            q.push(i);
        }
        
        while(!q.empty()){
            
            int fr = q.front();
            q.pop();
            
            if(fr>=low and fr<=high){
                res.push_back(fr);
            }
            
            if(fr > high)
                break;
            
            int num = fr % 10;
            if(num < 9) {
                q.push(fr * 10 + (num + 1));
            }
        }
        return res;
    }
};