class Solution {
public:
    string compressedString(string word) {
        
        string res = "";
        int n = word.size();
        
        int i;
        
        for(i=0;i<n;i++){
            char curr = word[i];
            int count = 8;
            int count1 = 1;
            while(i+1<n and word[i+1] == curr and count){
                i++;
                count--;
                count1++;
            }
            res += count1 + '0';
            res += curr;
            
            
        }
        return res;
    }
};