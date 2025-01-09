class Node{
public:
    Node *links[26];
    int count = 0;
    Node(){
        for(int i=0;i<=25;i++){
            links[i] = NULL;
        }
        count = 0;
    }

    void setCount(){
        count++;
    }

    int getCount(){
        return count;
    }

    bool containsKey(char ch){
        return links[ch-'a'];
    }

    void put(char ch, Node *node){
        links[ch-'a'] = node;
    }

    Node *get(char ch){
        return links[ch-'a'];
    }
};

class Trie{
    public:
    Node *root;

    Trie(){
        root = new Node();
    }

    void insert(string &s){
        int n = s.size();
        Node *temp = root;
        for(int i=0;i<n;i++){
            if(!temp->containsKey(s[i])){
                temp->put(s[i],new Node());
            }
            temp = temp->get(s[i]);
        }
        temp->setCount();
    }

    int getCount(string &s){
        int n = s.size();
        Node *temp = root;
        for(int i=0;i<n;i++){
            if(!temp->containsKey(s[i])){
                temp->put(s[i],new Node());
            }
            temp = temp->get(s[i]);
        }
        return temp->getCount();
    }
};
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int n = words.size();
        int i,j;

        Trie trie;
        for(i=0;i<n;i++){
            string temp = "";
            for(j=0;j<words[i].size();j++){
                temp += words[i][j];
                trie.insert(temp);
            }
        }

        return trie.getCount(pref);
    }
};