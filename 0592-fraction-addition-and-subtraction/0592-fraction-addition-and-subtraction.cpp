class Solution {
public:
    string fractionAddition(string expr) {
        
        int n = expr.size();
        int numo = 0;
        int deno = 1;

        int i=0;
        while(i<n){

            int currNum = 0;
            int currDen = 0;

            bool isNeg = (expr[i] == '-');

            if(expr[i] == '-' || expr[i] == '+'){
                i++;
            }

            while(i<n and isdigit(expr[i])){
                int val = expr[i] - '0';
                currNum = currNum * 10 + val;
                i++;
            }

            i++;

            if(isNeg) currNum *= -1;

            while(i<n and isdigit(expr[i])){
                int val = expr[i] - '0';
                currDen = currDen * 10 + val;
                i++;
            }

            numo = numo*currDen + currNum*deno;
            deno = currDen * deno;

            int k = __gcd(numo,deno);
            k = abs(k);

            numo/=k;
            deno/=k;
            
        }

        return to_string(numo) + "/" + to_string(deno);
    }
};