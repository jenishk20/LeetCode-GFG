class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int i;
        
        for(i=0;i<n-2;i++){
            if(arr[i]&1 and arr[i+1]&1 and arr[i+2]&1) return true;
        }
        return false;
    }
};