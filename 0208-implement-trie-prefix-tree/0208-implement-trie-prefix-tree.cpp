class Node{
    public:
    
    Node *links[26];
    bool flag = false;
    
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node *node){
        links[ch-'a'] = node;
    }
    
    Node *get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool getEnd(){
        return flag;
    }
};

class Trie {
    
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
    
         Node *node = root;
        for(int i = 0;i<word.size();i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node()); 
            }
            node = node->get(word[i]); 
        }
        node->setEnd(); 
    }
    
    bool search(string word) {
        
        Node *newNode = root;
        
        for(int i=0;i<word.size();i++){
            
            if(newNode->containsKey(word[i])){
                newNode = newNode->get(word[i]);
            }
            else{
                return false;
            }
        }
        
        if(newNode->getEnd()) return true;
        
        return false;
        
    }
    
    bool startsWith(string prefix) {
        Node *newNode = root;
        
        for(int i=0;i<prefix.size();i++){
            
            if(!newNode->containsKey(prefix[i])){
                return false;
            }
            newNode = newNode->get(prefix[i]);
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */