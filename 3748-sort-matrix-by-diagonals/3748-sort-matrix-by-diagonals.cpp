class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int i,j,k,l;

        for(i=0;i<n;i++){
            int st = i;
            int j = 0;
            vector<int>temp;
            while(st<n and j<m){
                temp.push_back(grid[st][j]);
                st++;
                j++;
            }
            sort(temp.begin(),temp.end(),[](int a,int b){
                return a>b;
            });

            st = i;
            j = 0;
            k=0;
            while(st<n and j<m){
                grid[st][j] = temp[k++];
                st++;
                j++;
            }
        }

        for(j=1;j<m;j++){
            int st = 0;
            int i = j;
            vector<int>temp;

            while(st<n and i<m){
                temp.push_back(grid[st][i]);
                st++;
                i++;
            }
            sort(temp.begin(),temp.end());

            st = 0;
            i = j;
            k=0;
             while(st<n and i<m){
                grid[st][i] = temp[k++];
                st++;
                i++;
            }

        }

        return grid;
    }
};