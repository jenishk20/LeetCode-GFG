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
    int res = 0;

    int recur(TreeNode *root){
        if(!root) return 0;
        if(!root->left and !root->right) return 1;

        int lh = recur(root->left);
        int rh = recur(root->right);
        int onlyMe =  lh + rh;
        int notMe = max(lh,rh);
        res = max({res,onlyMe,notMe});
        return notMe + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        if(!root->left and !root->right) return 0;
        recur(root);
        return res;
    }
};