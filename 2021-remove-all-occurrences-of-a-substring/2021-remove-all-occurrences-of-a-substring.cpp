class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();
        int m = part.size();

        int i,j;
        stack<char>se;

        for(i=0;i<n;i++){
            int j = m-1;
            string temp = "";
            while(!se.empty() and j>=0 and se.top() == part[j]){
                temp += se.top();
                se.pop();
                j--;
            }
            cout<<temp<<" "<<i<<" "<<j<<endl;
            if(j!=-1){
                for(int k = temp.size()-1;k>=0;k--) se.push(temp[k]);
            }

            se.push(s[i]);
        }

        j = m-1;
        string temp = "";
        while(!se.empty() and j>=0 and se.top() == part[j]){
            temp += se.top();
            se.pop();
            j--;
        }
        if(j!=-1){
            for(int k = temp.size()-1;k>=0;k--) se.push(temp[k]);
        }

        string res = "";
        while(!se.empty()){
            res += se.top();
            se.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};