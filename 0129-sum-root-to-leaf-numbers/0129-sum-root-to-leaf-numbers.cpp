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
    void recur(TreeNode *root,int &sum,string s){
        
        if(!root) {
            
            return;
        }
        s+=to_string(root->val);
        
        if(!root->left and !root->right){
            sum+=stoi(s);
        }
        // cout<<s<<endl;
        
        recur(root->left,sum,s);
        recur(root->right,sum,s);
        // cout<<s<<endl;
        
    }
    int sumNumbers(TreeNode* root) {
        
        int sum = 0;
        recur(root,sum,"");
        return sum;
    }
};