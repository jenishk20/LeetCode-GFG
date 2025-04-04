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
    int maxDepth = 0;
    unordered_map<int,int>depth;
    void recur(TreeNode *root,int d){
        if(!root) return;

        depth[root->val] = d;
        maxDepth = max(maxDepth,d);
        recur(root->left,d+1);
        recur(root->right,d+1);
    }

    TreeNode *lca(TreeNode *root){
        if(!root) return root;
        if(depth[root->val] == maxDepth) return root;

        auto left = lca(root->left);
        auto right = lca(root->right);

        if(left and right) return root;
        if(left) return left;
        return right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        recur(root,0);
        return lca(root);
    }
};