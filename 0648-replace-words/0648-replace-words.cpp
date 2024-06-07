class Node{
   
public:
    bool flag;
    Node *links[26];
    
    Node(){
        for(int i=0;i<=25;i++){
            links[i] = NULL;
        }
        flag = false;
    }
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    void put(char ch,Node *node){
        links[ch-'a'] = node;
    }
    
    Node *getNext(char ch){
        return links[ch-'a'];
    }
    
    void setFlag(){
        flag = true;
    }
    
    bool getFlag(){
        return flag;
    }
    
    
};

class Trie{
    
public:
    Node *root;
    Trie(){
        root = new Node();
    }
    
    void insert(string s){
        int n = s.size();
        int i;
        Node *curr = root;
        
        for(i=0;i<n;i++){
            if(!curr->containsKey(s[i])){
                curr->put(s[i],new Node());
            }
            curr = curr->getNext(s[i]);
        }
        curr->setFlag();
    }
    
    bool doesPrefixExists(string temp){
        
        Node *curr = root;
        int n = temp.size();
        
        for(int i=0;i<n;i++){
            if(!curr->containsKey(temp[i])){
                return false;
            }
            curr = curr->getNext(temp[i]);
        }
        return curr->getFlag();
    }
    
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        Trie trie;
        
        for(auto it : dictionary){
            trie.insert(it);
        }
        
        string word = "";
        string ans = "";
        
        for(int i=0;i<sentence.size();i++){
            
            if(sentence[i]==' '){
                
                bool be = false;
                string temp = "";
                for(int j=0;j<word.size();j++){
                    temp+=word[j];
                    if(trie.doesPrefixExists(temp)){
                        ans += word.substr(0,j+1);
                        be = true;
                        break;
                    }
                }
                
                if(!be) ans += word;
                ans += ' ';
                word = "";
            }
            else{
                word += sentence[i];
            }
        }
        
        bool be = false;
        string temp = "";
        for(int j=0;j<word.size();j++){
            temp+=word[j];
            if(trie.doesPrefixExists(temp)){
                ans += word.substr(0,j+1);
                be = true;
                break;
            }
        }

        if(!be) ans += word;

        return ans;
    }
};