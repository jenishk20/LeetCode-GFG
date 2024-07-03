class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
            
        int n = cardPoints.size();
        int i,j;
     
        
        int lSum = 0;
        int rSum = 0;
        
        
        for(i=0;i<k;i++){
            lSum += cardPoints[i];
        }
        
        j = n-1;
        int maxSum = lSum;
        
        for(i=k-1;i>=0;i--){
            lSum -= cardPoints[i];
            rSum += cardPoints[j--];
            maxSum = max(maxSum,lSum+rSum);
        }
        
        return maxSum;
    }   
};