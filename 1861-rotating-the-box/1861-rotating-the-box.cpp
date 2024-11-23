class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        int n = box.size();
        int m = box[0].size();
        
        int i = n-1 ,j = m-1;
        
        for(;i>=0;i--){
            for(j=m-1;j>=0;j--){
                if(box[i][j] == '#'){
                    
                    int nx = j+1;
                    int curr = j;
                    while(nx<m and box[i][nx] == '.'){
                        swap(box[i][curr],box[i][nx]);
                        curr = nx;
                        nx++;
                    }
                }
            }
        }
        
        vector<vector<char>>ans(m,vector<char>(n,'.'));
        
        int sti = 0;
        int stj = 0;
        
        for(i=0;i<m;i++){
            stj = 0;
            for(j=n-1;j>=0;j--){
                ans[sti][stj] = box[j][i];
                stj++;
            }
            sti++;
        }
        
        return ans;
        
    }
};