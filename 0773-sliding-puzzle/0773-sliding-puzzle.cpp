class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        map<int,vector<int>>ma;
        map<string,bool>done;

        ma[0] = {1,3};
        ma[1] = {0,2,4};
        ma[2] = {1,5};
        ma[3] = {0,4};
        ma[4] = {3,5,1};
        ma[5] = {4,2};

        string curr = "";
        string target = "123450";
        int st = 0;

        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                curr += to_string(board[i][j]);
                if(board[i][j] == 0){
                    st = i*3 + j;
                }
            }
        }

        queue<pair<string,int>>q;
        done[curr] = 1;
        
        q.push({curr,st});
        int ans = 0;

        while(!q.empty()){
            
            int sz = q.size();
            while(sz--){

                string cur = q.front().first;
                int idxOfZero = q.front().second;
                q.pop();

                if(cur == target) return ans;

                vector<int>pos = ma[idxOfZero];
                for(auto it : pos){
                    string ori = cur;
                    swap(cur[it],cur[idxOfZero]);

                    if(done.find(cur) == done.end()){
                        done[cur] = 1;
                        q.push({cur,it});
                    }
                    
                    cur = ori;
                }
            }
            ans++;
        }

        return -1;
    }
};