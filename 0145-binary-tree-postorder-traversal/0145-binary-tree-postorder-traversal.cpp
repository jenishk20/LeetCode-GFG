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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int>ans;
        
        if(!root) return ans;
        
        stack<TreeNode *>s1,s2;
        s1.push(root);
        
        while(!s1.empty()){
            
            auto curr = s1.top();
            s1.pop();
            
            s2.push(curr);
            
            if(curr->left) s1.push(curr->left);
            if(curr->right) s1.push(curr->right);
        }
        
        while(!s2.empty()){
            auto curr = s2.top();
            ans.push_back(curr->val);
            s2.pop();
        }
        
        return ans;
    }
};