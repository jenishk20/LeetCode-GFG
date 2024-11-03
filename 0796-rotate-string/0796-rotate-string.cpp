class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.size() != goal.size()) return false;
        
        string res = goal + goal;

        return res.find(s)!=string::npos;
    }
};