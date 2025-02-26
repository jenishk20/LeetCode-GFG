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
    bool ans = false;
    bool isSameTree(TreeNode *p,TreeNode *q){
        if(!p and !q) return true;
        if(p and !q) return false;
        if(!p and q) return false;
        if(p->val != q->val) return false;
        cout<<p->val<<" "<<q->val<<endl;
        return isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(root->val == subRoot->val){
            ans = ans or isSameTree(root,subRoot);
        }
        return ans or isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);

    }
};