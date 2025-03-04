class Solution {
public:
    vector<string>ans;

    bool isValid(string &s){
        int c1 = 0;
        for(auto it : s){
            if(it == '('){
                c1++;
            }
            else{
                c1--;
            }
            if(c1<0) return false;
        }
        return c1 == 0;
    }

    void generate(string &curr,int k){
        if(k==0){
            if(isValid(curr)) ans.push_back(curr);
            return;
        }
        curr += "(";
        generate(curr,k-1);
        curr.pop_back();
        curr += ")";
        generate(curr,k-1);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        generate(curr,2*n);
        return ans;
    }
};