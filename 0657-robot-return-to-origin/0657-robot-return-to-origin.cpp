class Solution {
public:
    bool judgeCircle(string moves) {
        
        int x = 0;
        int y = 0;

        for(auto it : moves){
            if(it == 'U') y--;
            else if(it == 'D') y++;
            else if(it == 'L') x--;
            else x++;
        }
        return x==0 and y==0;
    }
};