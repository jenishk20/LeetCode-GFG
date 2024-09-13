/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int recur(Node *root){
        if(!root) return 0;
        
        int maxi = 0;
        for(auto it : root->children){
            int res = recur(it);
            maxi = max(maxi,res);
        }
        return maxi + 1;
    }
    int maxDepth(Node* root) {
        return recur(root);
    }
};