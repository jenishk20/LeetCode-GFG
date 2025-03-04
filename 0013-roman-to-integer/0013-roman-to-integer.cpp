class Solution {
public:
    int romanToInt(string s) {
        map<char,int>values;
        values['I'] = 1;
        values['C'] = 100;
        values['X'] = 10;
        values['D'] = 500;
        values['M'] = 1000;
        values['V'] = 5;
        values['L'] = 50;

        int sum = 0;
        int i=0;
        while(i<s.size()){
            char curr = s[i];
            int val = values[curr];
            int next = 0;
            if(i+1<s.size()){
                next = values[s[i+1]];
            }

            if(val<next){
                sum += (next-val);
                i+=2;
            }
            else{
                sum += val;
                i++;
            }
        }
        return sum;
    }
};