class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'u' or ch == 'o';
    }
    long long countOfSubstrings(string word, int k) {
        long long ans = 0;
        int n = word.size();

        int i=0;
        int j=0;
        map<char,int>ma;
        vector<int>nextConso(n+1,0);
        int last = n;

        for(int i=n-1;i>=0;i--){
            if(isVowel(word[i])){
                nextConso[i] = last;
            }
            else{
                nextConso[i] = last;
                last = i;
            }
        }

        int conso = 0;

        while(j<n){
            if(isVowel(word[j])) ma[word[j]]++;
            else conso++;

            while(i<j and conso>k){
                if(isVowel(word[i])){
                    ma[word[i]]--;
                    if(ma[word[i]] == 0) ma.erase(word[i]);
                }
                else{
                    conso--;
                }
                i++;
            }

            if(ma.size() == 5 and conso == k){
                while(ma.size() == 5 and conso == k){
                    ans += nextConso[j] - j;
                    if(isVowel(word[i])){
                        ma[word[i]]--;
                        if(ma[word[i]] == 0) ma.erase(word[i]);
                    }
                    else{
                        conso--;
                    }
                    i++;
                }
            }
            j++;
        }

        return ans;

    }
};