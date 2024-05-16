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
    bool recur(TreeNode *root){
        
        if(!root) return false;
        
        if(!root->left && !root->right){
            return root->val;
        }
        
        
        bool op1 = recur(root->left);
        bool op2 = recur(root->right);
        
        int currVal = root->val;
        
        if(currVal==2) return op1 || op2;
        else return op1 && op2;
    }
    bool evaluateTree(TreeNode* root) {
        return recur(root);
    }
};