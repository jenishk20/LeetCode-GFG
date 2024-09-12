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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        
        if(!root) return ans;
        
        stack<TreeNode *>se;
        se.push(root);
        
        while(!se.empty()){
            
            auto curr = se.top();
            se.pop();
            ans.push_back(curr->val);
            
            if(curr->right) se.push(curr->right);
            if(curr->left) se.push(curr->left);
        }
        
        return ans;
    }
};