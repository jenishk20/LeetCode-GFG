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
    
    int recur(TreeNode *root,int &ans){
        if(!root) return 0;

        int lSum = max(0,recur(root->left,ans));
        int rSum = max(0,recur(root->right,ans));

        int op1 = lSum + rSum + root->val;
        
        ans = max({ans,op1});
        
        return max(lSum,rSum) + root->val;

    }
    int maxPathSum(TreeNode* root) {
        
        int ans = -1e9;
        recur(root,ans);
        return ans;
        
    }
};