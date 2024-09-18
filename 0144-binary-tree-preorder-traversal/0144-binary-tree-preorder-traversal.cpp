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
        
        TreeNode *curr = root;
        
        while(curr){
            
            ans.push_back(curr->val);
            if(curr->left == NULL){
                curr = curr->right;
            }

            else{
                
                TreeNode *left = curr->left;
                while(left->right){
                    left = left->right;
                }
                
                left->right = curr->right;
                
                TreeNode *temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }
        
        return ans;
    }
};