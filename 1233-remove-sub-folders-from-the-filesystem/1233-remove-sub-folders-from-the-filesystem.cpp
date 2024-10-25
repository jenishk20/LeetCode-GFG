class Node{
    public:
    Node *links[26];
    bool isEnd;
    
    Node(){
        for(int i=0;i<=25;i++){
            links[i] = NULL;
        }
        isEnd = false;
    }
    
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    
    void setEnd(){
        isEnd = true;
    }
    
    Node *next(char ch){
        return links[ch-'a'];
    }
    
    bool getEnd(){
        return isEnd;
    }
    
    void put(char ch,Node *node){
        links[ch-'a'] = node;
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
        Node *temp = root;
        
        for(i=0;i<n;i++){
            if(!temp->containsKey(s[i])){
                temp->put(s[i],new Node());
            }  
            temp = temp->next(s[i]);
        }
        temp->setEnd();
    }
    
    bool isSubSix(string s){
        int n = s.size();
        
        int i;
        Node *temp = root;
        
        for(i=0;i<n;i++){
            if(!temp->containsKey(s[i])){
                return false;
            }  
            temp = temp->next(s[i]);
            if(temp->getEnd()){
                return true;
            }
        }
       
        return false;
    }
   
};
class Solution {
public:
    map<string,string>convert(vector<string>&inp){
        vector<string>tt;
        
        map<string,string>ma;
        
        for(auto it : inp){
            string ans = "";
            for(int i=0;i<it.size();i++){
                if(it[i]>='a' and it[i]<='z'){
                    ans += it[i];
                }
            }
            tt.push_back(ans);
            ma[ans] = it;
        }
        
        return ma;
        
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        
        vector<string>ans;

        
        sort(folder.begin(),folder.end());

        stack<string>stk;
        stk.push(folder[0]);
        for(int i = 1; i<folder.size();i++)
        {
            string temp = stk.top() + '/';
            if(folder[i].compare(0,temp.size(),temp) == 0) // substring found 
                continue;
            else
                stk.push(folder[i]);
        }
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    
    }
};