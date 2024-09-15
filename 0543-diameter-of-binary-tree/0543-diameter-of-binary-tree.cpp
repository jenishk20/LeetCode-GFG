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
    int solve(TreeNode* root,int &res){
      if(!root)
          return 0;
        
        int l=solve(root->left,res);
        int r=solve(root->right,res);
        
        int op1 = l + r;
        int op2 = max(l,r);
        
        res=max({op1,op2,res});
        
        return max(l,r)+1 ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int res=INT_MIN;
        solve(root,res);
        return res;
    }
};