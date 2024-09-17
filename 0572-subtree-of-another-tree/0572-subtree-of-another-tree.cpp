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
    bool isSameTree(TreeNode *root1,TreeNode *root2){
        if(!root1 or !root2) return root1 == root2;
    
        if(root1->val != root2->val) return false;
        
        return isSameTree(root1->left,root2->left) && isSameTree(root2->right,root1->right);
        
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot) return root == subRoot;
        
        return isSameTree(root,subRoot) ||  isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};