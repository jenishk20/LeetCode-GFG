class Solution {
public:
    string frequencySort(string s) {
        map<char,int>ma;
        
        for(auto i:s)
            ma[i]++;
        
        string res = "";
        priority_queue<pair<int,int>>pq;
        for(auto it:ma){
            pq.push({it.second,it.first});
        }
        
        while(!pq.empty()){
            
            auto curr = pq.top();
            pq.pop();
            while(curr.first--)
                res+=curr.second;
        }
        return res;
    }
};