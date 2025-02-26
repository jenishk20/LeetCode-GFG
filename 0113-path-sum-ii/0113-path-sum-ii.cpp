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
    void recur(TreeNode *root,int targetSum,int currSum,vector<int>temp){
        if(!root) return;
        
        if(!root->left and !root->right and currSum + root->val == targetSum){
            temp.push_back(root->val);
            ans.push_back(temp);
            return;
        }
        temp.push_back(root->val);
        recur(root->left,targetSum,currSum + root->val,temp);
        recur(root->right,targetSum,currSum + root->val,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return ans;
        vector<int>temp;
        recur(root,targetSum,0,temp);
        return ans;
    }
};