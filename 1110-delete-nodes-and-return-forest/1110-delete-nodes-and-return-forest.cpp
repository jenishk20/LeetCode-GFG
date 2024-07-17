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
    TreeNode *dfs(TreeNode *root,set<int>&toBeDelete,vector<TreeNode *>&result){
        if(!root) return NULL;

        root->left = dfs(root->left,toBeDelete,result);
        root->right = dfs(root->right,toBeDelete,result);
        
        if(toBeDelete.count(root->val)){
            if(root->left) result.push_back(root->left);
            if(root->right) result.push_back(root->right);
            return NULL;
        }
        else{
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        set<int>deleteNodes(to_delete.begin(),to_delete.end());
        vector<TreeNode *>result;
        dfs(root,deleteNodes,result);
        if(!deleteNodes.count(root->val)){
            result.push_back(root);
        }
        return result;
    }
};