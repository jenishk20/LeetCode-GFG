class Solution {
public:
    bool checkInclusion(string s1, string s2) {
          int n = s1.size();
        int m = s2.size();
        
        int i,j;
        vector<int>v1(26,0);
        vector<int>v2(26,0);

        for(i=0;i<n;i++){
            v1[s1[i]-'a']++;
        }

        i=0;
        j=0;
        while(j<m){
            v2[s2[j]-'a']++;

            if(j-i+1>n){
                v2[s2[i]-'a']--;
                i++;
            }
            
            if(v1 == v2) return true;
            j++;
        }
        return false;
        
    
    }
};