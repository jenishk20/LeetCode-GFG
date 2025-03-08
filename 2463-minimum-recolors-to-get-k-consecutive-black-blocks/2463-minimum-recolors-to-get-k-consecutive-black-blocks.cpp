class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int n = blocks.size();
        int i=0,j=0;
        int cW = 0, cB = 0;
        int ans = 1e9;

        while(j<n){
            if(blocks[j] == 'W') cW++;
            else cB++;

            while(i<j and cB + cW > k){
                if(blocks[i] == 'W') cW--;
                else cB--;
                i++;
            }
            cout<<i<<" "<<j<<" "<<cB<<" "<<cW<<endl;
            if(cB + cW >= k){
                ans = min(ans,cW);  
            }
            j++;
        }   
        return ans;
    }
};