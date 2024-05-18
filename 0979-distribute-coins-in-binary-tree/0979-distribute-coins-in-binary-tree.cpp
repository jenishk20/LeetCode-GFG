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
        
        int left = recur(root->left,ans);
        int right = recur(root->right,ans);
        
        ans += abs(left) + abs(right);
        
        return left + right - 1 + root->val;
    }
    int distributeCoins(TreeNode* root) {
        
        int ans = 0;
        recur(root,ans);
        return ans;
    }
};