class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int diff1 = abs(coordinate2[0]-'0' - (coordinate1[0]-'0'));
        int diff2 = abs(coordinate2[1]-'0' - (coordinate1[1]-'0'));
        
        return diff1%2 == diff2%2;
    }
};