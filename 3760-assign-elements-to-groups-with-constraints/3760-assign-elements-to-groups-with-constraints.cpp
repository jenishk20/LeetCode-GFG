class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        
        int n = groups.size();
        int i;

        vector<int>res(n,1e9);
        map<int,vector<int>>ma;

        for(int j=0;j<elements.size();j++){
            ma[elements[j]].push_back(j);
        }

        for(i=0;i<n;i++){
            
            for(int j=1;j*j<=groups[i];j++){
                if(groups[i]%j == 0){
                    int firstMul = j;
                    int secondMul = groups[i]/j;
                    if(ma.find(firstMul) != ma.end()){
                        res[i] = min({res[i],ma[firstMul][0]});
                    }
                    if(ma.find(secondMul) != ma.end()){
                        res[i] = min({res[i],ma[secondMul][0]});
                    }
                    
                }
            }
            if(res[i] == 1e9) res[i] = -1;
        }
        return res;
    }
};