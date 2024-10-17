class Solution {
public:
    int maximumSwap(int num) {
        
        string s = to_string(num);
        int n = s.size();
        
        int i;
        vector<int>last(10,-1);
        
        for(i=n-1;i>=0;i--){
            last[s[i]-'0'] = max(last[s[i]-'0'],i);
        }
        
        for(i=0;i<n;i++){
            for(int dig = 9;dig>=1;dig--){
                if(dig>s[i]-'0' and last[dig]!=-1 and last[dig]>i){
                    swap(s[last[dig]],s[i]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};