class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();

        int depth = 0;

        for(int i=0;i<n;i++){
            if(logs[i][0]!='.'){
                depth++;
            }
            else if(logs[i][0] == '.' and logs[i][1] == '.'){
                depth = max(0,depth-1);
            }
        }
        return depth;
    }
};