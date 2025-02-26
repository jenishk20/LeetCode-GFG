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
    vector<vector<int>>ans;
    void recur(vector<int>&temp,TreeNode *root, TreeNode *parent){
        if(!root) return;
        if(!root->left and !root->right){
            if(parent == NULL){
                temp.push_back(root->val);
                return;
            }
            if(parent->left == root) parent->left = NULL;
            if(parent->right == root) parent->right = NULL;
            temp.push_back(root->val);
            return;
        } 
        recur(temp,root->left,root);
        recur(temp,root->right,root);
    }
    vector<vector<int>> findLeaves(TreeNode* root,TreeNode *parent = NULL) {

        while(root->left or root->right){
            vector<int>temp;

            cout<<root->val<<endl;
            recur(temp,root,NULL);
            ans.push_back(temp);
        }
        
        if(!root->left and !root->right) ans.push_back({root->val});
        return ans;
    }
};