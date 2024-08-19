class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        vector<char>mutations = {'A','T','C','G'};
        map<string,int>banks;
        
        for(auto it : bank){
            banks[it]++;
        }
        map<string,int>vis;
        
        queue<pair<string,int>>q;
        
        q.push({startGene,0});
        vis[startGene] = 1;
        
        while(!q.empty()){
            
            auto curr = q.front();
            q.pop();
            
            
            if(curr.first == endGene) return curr.second;
            
            string gene = curr.first;
            
            for(int i=0;i<gene.size();i++){
                
                for(int j=0;j<4;j++){
                    if(gene[i] != mutations[j]){
                        
                        char prev = gene[i];
                        gene[i] = mutations[j];
                        
                        if(banks[gene] and !vis[gene]){
                            q.push({gene,curr.second+1});
                            vis[gene] = 1;
                        }
                        gene[i] = prev;
                    }
                }
                
            }
            
        }
        return -1;
    }
};