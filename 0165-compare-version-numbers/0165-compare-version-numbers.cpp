class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int n = version1.size();
        int m = version2.size();
        
        int i=0,j=0;
        
        string s1 = "",s2 = "";
        
        while(i<n || j<m){
            
            int num1 = 0;
            int num2 = 0;
            
            while(i<n and version1[i]!='.'){
                if(s1.size() == 0 && version1[i]=='0'){
                    i++;
                    continue;
                }
                s1+=version1[i++];
            }
            
            while(j<m and version2[j]!='.'){
                if(s2.size() == 0 && version2[j]=='0'){
                    j++;
                    continue;
                }
                s2+=version2[j++];
            
            }
            
            if(s1.size() < s2.size()) return -1;
            else if(s2.size() < s1.size()) return 1;
            
            int ans = s1.compare(s2);
            if(ans < 0) return -1;
            else if(ans > 0) return 1;
            
            s1 = "";
            s2 = "";
            
            i++;
            j++;
            
        }
        return 0;
    }
};