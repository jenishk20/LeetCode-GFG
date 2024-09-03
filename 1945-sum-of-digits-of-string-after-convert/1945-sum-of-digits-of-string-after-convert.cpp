class Solution {
public:
    int getSum(int k){

        int sum = 0;
        while(k){
            sum += k%10;
            k/=10;
        }
        return sum;
    }
    int getLucky(string s, int k) {

        int sum = 0;
        for(char &ch : s) {
		    int val = ch-'a'+1;
		    sum += val < 10 ? val : (val%10 + val/10);
		}
        k--;

        while(k and sum>=10){
            sum = getSum(sum);
            k--;
        }

        return sum;
    }
};