class Solution {
public:

    long long dividePlayers(vector<int>& skill) {
        
        sort(skill.begin(),skill.end());
        int n = skill.size();

        int i=0,j=n-1;
        set<int>se;
        long long sum = 0;

        while(i<j){
            se.insert(skill[i]+skill[j]);
            sum += skill[i]*skill[j];
            i++;
            j--;
        }
        return (se.size() == 1 ? sum : -1);    
    }
};