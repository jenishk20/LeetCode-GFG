class Solution {
public:
    string smallestNumber(string pattern) {
        
        int n = pattern.size();
        stack<char>st;
        string res = "";

        int cnt = 1;

        for(int i=0;i<=n;i++){
            st.push(cnt + '0');
            cnt++;
            if(i>=n or pattern[i] == 'I'){
                while(!st.empty()){
                    res += st.top();
                    st.pop();
                }
            }
        }
        return res;
        
    }
};