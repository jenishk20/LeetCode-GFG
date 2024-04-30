class Solution {
public:
    bool checkValidString(string s) {
        
        int n = s.size();
        
        int leftMin = 0, leftMax =0;
        
        int ans = 0;
        
        int i;
        
        for(i=0;i<n;i++){
            
            if(s[i]=='('){
                leftMin++;
                leftMax++;
            }
            else if(s[i]==')'){
                leftMin--;
                leftMax--;
            }
            else{
                
                leftMin--;
                leftMax++;
            }
            
            if(leftMax<0) return false;
            
            leftMin = max(0,leftMin);
        }
        
        return leftMin == 0;
    }
};