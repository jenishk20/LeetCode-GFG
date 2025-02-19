class Solution {
public:
    void recur(int idx,int n,int k,vector<string>&ans,string curr, char prevChar){
        if(idx == n){
            cout<<curr<<endl;
            ans.push_back(curr);
            return;
        }

        for(char ch = 'a';ch<='c';ch++){
            if(ch != prevChar){
                curr += ch;
                recur(idx+1,n,k,ans,curr,ch);
                curr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {

        vector<string>ans;
        string curr = "";
        char prevChar = ' ';
        recur(0,n,k,ans,curr,prevChar);

        if(ans.size()<k) return "";
        return ans[k-1];
    }
};