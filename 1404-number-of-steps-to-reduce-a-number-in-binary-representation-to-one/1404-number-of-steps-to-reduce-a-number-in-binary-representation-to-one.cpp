class Solution {
public:
    int numSteps(string s) {
       
        int n = s.size();
        int i;
        
        int cnt = 0;
        int r = n-1;
        int carry = 0;
        
        while(r){
            
            if(s[r]=='0' and carry==0){
                cnt++;
            }
            else if(s[r]=='1' and carry==0){
                carry=1;
                cnt+=2;
            }
            else if(s[r]=='1' and carry==1){
                carry = 1;
                cnt++;
            }
            else if(s[r]=='0' and carry==1){
                cnt+=2;
                carry = 1;
            }
            cout<<cnt<<" "<<carry<<endl;
            r--;
        }
        return carry?cnt+1:cnt;
    }
};