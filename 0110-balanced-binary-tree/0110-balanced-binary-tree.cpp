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
    int recur(TreeNode *root,bool &be){
        if(!root) return 0;
        
        int lh = recur(root->left,be);
        int rh = recur(root->right,be);
    
        if(abs(lh-rh)>1) be = false;
        
        return max(lh,rh) + 1 ;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        bool be = true;
        recur(root,be);
        return be;
    }
};