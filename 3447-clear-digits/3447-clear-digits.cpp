class Solution {
public:
    string clearDigits(string s) {
        
        int n = s.size();
        int charIdx = -1;

        while(1){
            bool be = false;
            for(int i=0;i<s.size();i++){
                if(isdigit(s[i])){
                    if(charIdx!=-1){
                        s.erase(charIdx,1);
                        s.erase(i-1,1);
                        be = true;
                        break;
                    }
                }
                else{
                    charIdx = i;
                }
            }
            if(!be) break;
        }
        return s;
    }
};