class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        
        colors.insert(colors.end(),colors.begin(),colors.end());
        int n = colors.size();

        for(auto it : colors){
            cout<<it<<" ";
        }

        int i = 0;
        int j = 1;
        set<int>se;

        while(j<n){
            if(colors[j] == colors[j-1]){
                i = j;
                j++;
                continue;
            }

            if(j-i+1 == k){
                se.insert(i%(n/2));
                i++;
            }
            j++;
        }
        return se.size();
        
    }
};