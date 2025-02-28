class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> numSet(arr.begin(), arr.end());

        int maxLen = 0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int toFind = arr[i] + arr[j];
                int prev = arr[j];
                int currLen = 2;

                while(numSet.count(toFind)){
                    int temp = toFind;
                    toFind = prev + toFind;
                    prev = temp;
                    currLen++;
                    maxLen = max(maxLen,currLen);
                }
                
            }
        }
        return maxLen;
    }
};