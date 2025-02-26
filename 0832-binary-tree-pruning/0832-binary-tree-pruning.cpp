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
        if(!root) return 0;
        if(!root->left and !root->right) return root->val == 1;

        int lh = recur(root->left);
        int rh = recur(root->right);

        if(!lh) root->left = NULL;
        if(!rh) root->right = NULL;

        return root->val or lh or rh;
    }
    TreeNode* pruneTree(TreeNode* root) {

        recur(root);
        if(!root->left and !root->right and root->val == 0) return NULL;
        return root;
    }
};