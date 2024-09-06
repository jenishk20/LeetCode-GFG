class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sumOfExistingRolls = accumulate(rolls.begin(),rolls.end(),0);
        int unknownSum = mean*(n+m) - sumOfExistingRolls;
        vector<int>res;
        
        int maxUnknownSum = n*6;
        if(unknownSum > maxUnknownSum  || unknownSum < n) return {};

        if(unknownSum == maxUnknownSum) return vector<int>(n,6);

        if(unknownSum%n == 0) return vector<int>(n,unknownSum/n);
        
        cout<<unknownSum<<" "<<n<<endl;
        for(int i=n;i>=1;i--){
            int k = min(6,unknownSum - i +1);
            res.push_back(k);
            unknownSum -= k;
        }
        
        return res;

    }
};