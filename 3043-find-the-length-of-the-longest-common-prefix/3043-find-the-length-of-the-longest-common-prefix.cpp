class Node{
public:
    
    Node *links[11];
    bool isEnd;
    
    Node(){
        for(int i=0;i<=10;i++){
            links[i] = NULL;
        }
        isEnd = false;
    }
    
    void put(char ch,Node *node){
        
        links[ch-'0'] = node;
    }
    
    bool containsKey(char ch){
        return links[ch-'0'] != NULL;
    }
    
    Node *next(char ch){
        return links[ch-'0'];
    }
    
};

class Trie{
    
public:
    Node *root;
    
    Trie(){
        root = new Node();    
    }
    
    void insert(int x){
        
        string s = to_string(x);
        
        Node *curr = root;
        
        for(int i=0;i<s.size();i++){
            if(!curr->containsKey(s[i])){
                curr->put(s[i],new Node());
            }
            curr = curr->next(s[i]);
        }
    }
    
    int calcMaxPrefix(int x){
        
        int cnt = 0;
        string s = to_string(x);
        
        Node *curr = root;
        
        for(int i=0;i<s.size();i++){
            if(!curr->containsKey(s[i])){
                return cnt;
            }
            curr = curr->next(s[i]);
            cnt++;
        }
        return cnt;
    }
    
};


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        Trie *trie = new Trie();
        
        for(auto it : arr1){
            trie->insert(it);
        }
        
        int maxi = 0;
        
        for(auto it : arr2){
            
            int ans = trie->calcMaxPrefix(it);
            maxi = max(maxi,ans);
        }
        
        return maxi;
    }
};