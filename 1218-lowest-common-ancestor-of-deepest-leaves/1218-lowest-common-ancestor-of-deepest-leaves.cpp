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

    pair<TreeNode *,int> find(TreeNode *root){
        if(!root) return {NULL,0};

        pair<TreeNode*,int> l = find(root->left);
        pair<TreeNode*,int> r = find(root->right);

        if(l.second == r.second){
            return {root,l.second+1};
        }
        else if(l.second > r.second){
            return {l.first,l.second+1};
        }
        else{
            return {r.first,r.second+1};
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return find(root).first;
    }
};