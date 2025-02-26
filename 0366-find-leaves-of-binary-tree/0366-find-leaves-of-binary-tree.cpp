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
    map<int,vector<int>>ma;
    int recur(TreeNode *root){
        if(!root) return 0;
        int lh = recur(root->left);
        int rh = recur(root->right);

        int myIndex = max(lh,rh) + 1;
        ma[myIndex].push_back(root->val);
        return myIndex;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {

        vector<vector<int>>ans;
        
        recur(root);

        for(auto it : ma) ans.push_back(it.second);
        return ans;

    }
};