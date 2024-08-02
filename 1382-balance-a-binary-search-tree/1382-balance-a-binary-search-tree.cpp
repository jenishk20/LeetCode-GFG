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
    
    void traverse(TreeNode *root,vector<int>&inorder){
        if(!root) return;
        
        traverse(root->left,inorder);
        inorder.push_back(root->val);
        traverse(root->right,inorder);
    }
    
    TreeNode *constructTree(int l,int r,vector<int>&inorder){
        if(l>r) return NULL;
        
        int mid = (l+r)/2;
        
        TreeNode *root = new TreeNode(inorder[mid]);
        
        root->left = constructTree(l,mid-1,inorder);
        root->right = constructTree(mid+1,r,inorder);
        
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int>inorder;
        traverse(root,inorder);
        
        int n = inorder.size();
        return constructTree(0,n-1,inorder);
    }
};