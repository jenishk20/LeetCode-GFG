class Solution {
public:
    vector<int>ans;
    void recur(string curr,int n){
        
        int currRes = stoi(curr);
        if(currRes > n) return;
        
        ans.push_back(currRes);
        
        for(int i=0;i<=9;i++){
            recur(curr + to_string(i),n);
        }
    }
    vector<int> lexicalOrder(int n) {
        
        for(int i=1;i<=9;i++){
            recur(to_string(i),n);
        }

        return ans;
    }
};