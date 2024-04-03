class Node {
    
    map<pair<char,char>,Node *>ma;
    int count;
    public:
    Node(){
        count = 0;
    }
    
    bool containsKey(pair<char,char>p)
    {
        return ma.find(p)!=ma.end();
    }
    
    int getCount(){
        return count;
    }
    
    void setCount(){
        count++;
    }
    
    void put(pair<char,char>p,Node *newNode){
        ma[p] = newNode;
    }
    
    Node *get(pair<char,char>p){
        return ma[p];
    }
    
    
};

class Trie {
  
    private:
    Node *root;
    
    public:
    Trie(){
        root = new Node();    
    }
      
    long long insert(string s){
        int n = s.size();
        Node *curr = root;
        
        long long int ans = 0;
        
        for(int i=0;i<n;i++){
            
            pair<char,char>firstLast = {s[i],s[n-i-1]};
            
            if(!curr->containsKey(firstLast)){
                curr->put(firstLast,new Node());
            }
            curr = curr->get(firstLast);
            ans += curr->getCount();
            
        }
        
        curr->setCount();
        return ans;
    }
    
    
    
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        
        Trie trie;
    
        long long ans = 0;
        for(auto i:words){
            ans += trie.insert(i);
        }
        
        return ans;
    }
};