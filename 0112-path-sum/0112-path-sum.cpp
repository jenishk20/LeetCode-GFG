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
    bool recur(TreeNode *root,int targetSum,int currSum){
        if(!root) return false;
        currSum += root->val;
        if(!root->left and !root->right) return currSum == targetSum;

        return recur(root->left,targetSum,currSum) or recur(root->right,targetSum,currSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return recur(root,targetSum,0);
    }
};