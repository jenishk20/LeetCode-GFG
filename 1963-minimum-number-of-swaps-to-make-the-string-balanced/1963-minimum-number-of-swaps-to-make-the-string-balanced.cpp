class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int i;

        stack<char>se;
        int cnt = 0;

        for(int i=0;i<n;i++){
            if(s[i] == '['){
                se.push(s[i]);
            }
            else{
                if(se.empty()) cnt++;
                else se.pop();
            }
        }

        return (cnt+1)/2;
    }
};