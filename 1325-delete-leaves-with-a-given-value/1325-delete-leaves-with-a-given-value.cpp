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
//     TreeNode *recur(TreeNode *root,int target){
        
//         if(!root) return NULL;
        
//         if(!root->left and !root->right and root->val == target)
//             return root;
        
//         TreeNode *left = recur(root->left,target);
//         TreeNode *right = recur(root->right,target);
        
//         if(left && left->val == target) root->left = NULL;
//         if(right && right->val == target) root->right = NULL;
        
//         if(left && right){
//             cout<<root->val<<" "<<left->val<<" "<<right->val<<endl;
//         }
//         else if(left){
//             cout<<root->val<<" "<<left->val<<" "<<"NOT PRESENT"<<endl;
//         }
//         else if(right){
//             cout<<root->val<<" "<<"NOT PRESENT"<<" "<<right->val<<endl;
//         }
//         // cout<<root->val<<" "<<left->val<<" "<<right->val<<endl;
//         return root;
//     }
    
    bool recur(TreeNode *root,int target){
        if(!root) return false;
        
        if(!root->left and !root->right and root->val == target)
            return true;
        
        bool left = recur(root->left,target);
        bool right = recur(root->right,target);

        if(left) root->left = NULL;
        if(right) root->right = NULL;
      
        if(left and !root->right) {
            return root->val == target;
        }
        if(right and !root->left){
            return root->val == target;
        }
        
        return false;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        bool ans = recur(root,target);
        if(ans && root->val == target and !root->left
          and !root->right) return NULL;
        return root;
    }
};