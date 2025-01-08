class Node{
public:
    Node *links[26];
    bool isEnd;
    Node(){
        for(int i=0;i<26;i++){
            links[i] = NULL;
        }
        this->isEnd = true; 
    }

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }

    void put(char ch,Node *node){
        links[ch-'a'] = node;
    }

    void setEnd(){
        this->isEnd = true;
    }

    bool getEnd(){
        return this->isEnd;
    }

    Node *next(char ch){
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

        for(int i=0;i<s.size();i++){
            if(!temp->containsKey(s[i])){
                temp->put(s[i],new Node());;
            }
            temp = temp->next(s[i]);
        }
        temp->setEnd();
    }

    bool isPrefix(string &s){
        int n = s.size();
        Node *temp = root;

        for(int i=0;i<s.size();i++){
            if(!temp->containsKey(s[i])){
                return false;
            }
            temp = temp->next(s[i]);
        }
        return temp->getEnd();
    }
};
class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        
        long long cnt = 0;
        
        for(int i=0;i<words.size();i++){
            Trie prefix,suffix;

            prefix.insert(words[i]);
            string revWord = words[i];
            reverse(revWord.begin(), revWord.end());
            suffix.insert(revWord);

            for(int j=0;j<i;j++){
                if(words[j].size() > words[i].size()) continue;

                string curr = words[j];
                reverse(curr.begin(),curr.end());

                if(prefix.isPrefix(words[j]) and suffix.isPrefix(curr)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};