class Solution {
public:
    int dp[1001][1001];
int recur(int idx,int shelfWidth,int currentWidth,vector<vector<int>>&books,int maxHeight){

    if(idx>=books.size()) return maxHeight;

    if(dp[idx][currentWidth] != -1) return dp[idx][currentWidth];

    int op1 = 1e7,op2 = 1e7;

    if(books[idx][0]<=currentWidth){
        op1 = recur(idx+1,shelfWidth,currentWidth-books[idx][0],books,max(books[idx][1],maxHeight));
    }
    op2 = maxHeight + recur(idx+1,shelfWidth,shelfWidth-books[idx][0],books,books[idx][1]);

    return dp[idx][currentWidth] = min(op1,op2);
}
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        
        int n = books.size();
        memset(dp,-1,sizeof dp);
        return recur(0,shelfWidth,0,books,0);
    }
};