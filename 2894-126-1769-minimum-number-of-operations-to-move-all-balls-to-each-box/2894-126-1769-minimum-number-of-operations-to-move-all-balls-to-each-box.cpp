class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int balls = 0;
        int moves = 0;

        int i;
        vector<int>ans(n,0);

        for(i=0;i<n;i++){
            ans[i] += balls + moves;
            moves = moves + balls;
            if(boxes[i] == '1') balls++;
        }

        balls = 0;
        moves = 0;

        for(i=n-1;i>=0;i--){
            ans[i] += balls + moves;
            moves = moves + balls;
            if(boxes[i] == '1') balls++;
        }
        return ans;
    }
};