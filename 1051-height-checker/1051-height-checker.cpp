class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        int n = heights.size();
        
        vector<int>counts(101,0);
        vector<int>b(n,0);
        
        for(int i=0;i<n;i++){
            counts[heights[i]]++;
        }
        
        for(int i=0;i<=100;i++){
            counts[i] += (i-1>=0)?counts[i-1]:0;
        }
        
        int cnt = 0;
        for(int i=n-1;i>=0;i--){
            
            b[counts[heights[i]]-1] = heights[i];
            if(b[counts[heights[i]]-1]!= heights[counts[heights[i]]-1]) cnt++; 
            counts[heights[i]]--;
        }
        

        return cnt;
        
    }
};