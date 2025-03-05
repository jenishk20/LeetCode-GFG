class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        int i,j;
        int maxi = 0;
        int indx = -1;

        for(i=n-2;i>=0;i--){
            if(a[i]<a[i+1]){
                indx = i;
                break;
            }
        }

        if(indx == -1){
            reverse(a.begin(),a.end());
            return;
        }

        int mini = 1e9;
        int pos = -1;

        for(i=indx+1;i<n;i++){
            if(a[i]>a[indx] and a[i]<mini){
                mini = a[i];
                pos = i;
            }
        }
        swap(a[indx],a[pos]);
        sort(a.begin()+indx+1,a.end());
        
    }
};