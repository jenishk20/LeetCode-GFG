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
    int sumOfLeftLeaves(TreeNode* root) {
        
        queue<TreeNode *>q;
        q.push(root);
        
        int sum = 0;
        
        while(!q.empty()){
            
            int sz = q.size();
            while(sz--){
                auto curr = q.front();
                q.pop();
                
                if(curr->left){
                    if(!curr->left->left && !curr->left->right)
                        sum+=curr->left->val;
                    q.push(curr->left);
                }
                
                if(curr->right)
                    q.push(curr->right);
            }
        }
        
        return sum;
        
        
    }
};