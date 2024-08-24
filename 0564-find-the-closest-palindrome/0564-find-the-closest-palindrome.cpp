class Solution {
public:
    typedef long long ll;
    
    ll generate(ll num, bool isEven){
        
        ll result = num;
        
        if(isEven){
             while(num){
                result = result * 10 + num%10;
                num/=10;
            }
        }
        else{
            num/=10;
            while(num){
                result = result * 10 + num%10;
                num/=10;
            }
        }
        return result;
    }
    string nearestPalindromic(string n) {
        
        int sz = n.size();
        
        int firstHalfLength = (sz%2 == 0) ? sz/2 : sz/2 + 1;
        
        ll firstHalfInt = stol(n.substr(0,firstHalfLength));
        
        set<ll>results;
        
        results.insert(generate(firstHalfInt,sz%2==0));
        results.insert(generate(firstHalfInt+1,sz%2==0));
        results.insert(generate(firstHalfInt-1,sz%2==0));
        results.insert(pow(10,sz)+1);
        results.insert(pow(10,sz-1) - 1);
        results.erase(stol(n));
        
        ll ans = 0;
        ll diff = 1e18;
        
        for(auto it : results){
            if(abs(it-stol(n))<diff){
                diff = abs(it-stol(n));
                ans = it;
            }
        }
        
        return to_string(ans);
        

    }
};