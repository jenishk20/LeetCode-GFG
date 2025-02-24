class Solution {
public:
    void recur(int st,int en,vector<char>&s){
        if(st>en) return;
        swap(s[st],s[en]);
        recur(st+1,en-1,s);
    }
    void reverseString(vector<char>& s) {
        recur(0,s.size()-1,s);
    }
};