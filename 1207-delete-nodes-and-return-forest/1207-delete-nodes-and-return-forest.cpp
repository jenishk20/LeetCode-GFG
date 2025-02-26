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
    vector<TreeNode *>ans;
    void recur(TreeNode *root, TreeNode *parent, vector<int>&to_delete){
        if(!root) return;
        
        recur(root->left,root,to_delete);
        recur(root->right,root,to_delete);

        if(find(to_delete.begin(),to_delete.end(),root->val)!=to_delete.end()){
            if(parent and parent->left == root) parent->left = NULL;
            if(parent and parent->right == root) parent->right = NULL;
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            return;
        }
        if(!parent) ans.push_back(root);

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        recur(root,NULL,to_delete);
        return ans;
    }
};