class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        map<char,int>sHash,pHash;
        
        for(auto i:t)
            pHash[i]++;
        
        int i=0,j=0;
        int count=0;
        int ml=1e9;
        int st=-1;
        while(j<n)
        {
            sHash[s[j]]++;
            if(sHash[s[j]]<=pHash[s[j]])
                count++;
            if(count==m)
            {
                while(sHash[s[i]]>pHash[s[i]] or pHash[s[i]]==0)
                {
                    if(sHash[s[i]]>pHash[s[i]])
                        sHash[s[i]]--;
                    i++;
                }
                if(j-i+1<ml)
                {
                    ml=j-i+1;
                    st=i;
                }
            }
            j++;
            
        }
        if(st==-1) return "";
        return s.substr(st,ml);
        
    }
};