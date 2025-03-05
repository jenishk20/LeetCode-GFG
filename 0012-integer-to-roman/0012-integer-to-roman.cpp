class Solution {
public:
    string intToRoman(int num) {
        
        map<int,string>ma;

        ma[1000] = "M";
        ma[900] = "CM";
        ma[500] = "D";
        ma[400] = "CD";
        ma[100] = "C";
        ma[90] = "XC";
        ma[50] = "L";
        ma[40] = "XL";
        ma[10] = "X";
        ma[9] = "IX";
        ma[5] = "V";
        ma[4] = "IV";
        ma[1] = "I";

        vector<pair<int,string>>ve;
        for(auto it : ma){
            ve.push_back({it.first,it.second});
        }
        sort(ve.begin(),ve.end(),[](pair<int,string>&a,pair<int,string>&b){
            return a.first > b.first;
        });

        int st = 0;
        string res = "";

        while(num){
            while(num >= ve[st].first){
                res += ve[st].second;
                num -= ve[st].first;
            }
            st++;
        }
        return res;
    }
};