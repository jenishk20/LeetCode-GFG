/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,char>ma;
    string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    void recur(TreeNode *root,string s){
        if(!root){
            return;
        }
        
        s+=ma[root->val];
        if(!root->left && !root->right){
            reverse(s.begin(),s.end());
            ans = min(ans,s);
        }
        
        recur(root->left,s);
        recur(root->right,s);
    }
    string smallestFromLeaf(TreeNode* root) {
        
        char ch ='a';
        for(int i=0;i<=25;i++){
            ma[i] = ch++;
        }
        string s= "";
        recur(root,s);
        return ans;
    }
};