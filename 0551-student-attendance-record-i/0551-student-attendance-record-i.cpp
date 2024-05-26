class Solution {
public:
    bool checkRecord(string s) {
        
        int n = s.size();
        
        int cntLate = 0;
        
        for(int i=0;i<n;i++){
            if(s[i] == 'A'){
                cntLate++;
            }
            else if(s[i]=='L'){
                int have = 0;
                while(i<n and s[i]=='L'){
                    i++;
                    have++;
                }
                if(have>=3) return false;
                i--;
            }
        }
        cout<<cntLate<<endl;
        return cntLate<2;
    }
};