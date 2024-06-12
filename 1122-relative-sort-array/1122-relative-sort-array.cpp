class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        vector<int>ans;
        
        int n = arr1.size();
        int m = arr2.size();
        
        vector<int>count(1001,0);
        
        for(auto it : arr1){
            count[it]++;
        }
        
        int st = 0;
        
        for(auto it : arr2){
            while(count[it]){
                arr1[st++] = it;
                count[it]--;
            }
        }
        
        for(int i=0;i<1001;i++){
            if(count[i]){
                while(count[i]--){
                    arr1[st++] = i;
                }
            }
        }
        
        return arr1;
    }
};