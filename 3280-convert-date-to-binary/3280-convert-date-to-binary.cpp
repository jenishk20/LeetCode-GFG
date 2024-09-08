class Solution {
public:
    
    string binaryString(int x){
        
        int i;
        for(i=31;i>=0;i--){
            
            if(x&(1<<i)){
                break;
            }
        }
        
        string res = "";
        for(int j=i;j>=0;j--){
            if(x&(1<<j)) res += "1";
            else res += "0";   
        }
        
        return res;
    }
    string convertDateToBinary(string date) {
        
        string res = "";
        
        string year = date.substr(0,4);
        string month = date.substr(5,2);
        string day = date.substr(8,2);
        
        int yeari = stoi(year);
        int monthi = stoi(month);
        int dayi = stoi(day);

        return binaryString(yeari) + "-" + binaryString(monthi) + "-" + binaryString(dayi);
    }
};