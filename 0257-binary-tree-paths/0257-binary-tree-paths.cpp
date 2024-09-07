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
    vector<string>res;
    void recur(TreeNode *root,string se)
    {
        if(!root)
            return;
        se+=(to_string(root->val));
         se+="->";
        if(root->left==NULL && root->right==NULL)
        {
            se.pop_back();
            se.pop_back();
            res.push_back(se);
            return;
        }
       
        recur(root->left,se);
        recur(root->right,se);
        
        
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        string se="";
       
        recur(root,se);
        return res;
    }
};