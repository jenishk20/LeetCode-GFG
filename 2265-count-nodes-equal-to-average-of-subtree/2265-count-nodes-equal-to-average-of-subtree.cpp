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
    pair<int,int> recur(TreeNode *root,int &cnt){
        
        if(!root) return {0,0};
        
        if(!root->left and !root->right) {
            cnt++;
            return {1,root->val};
        };
        
        auto left = recur(root->left,cnt);
        auto right = recur(root->right,cnt);
        
        int countOfNodes = left.first + right.first + 1;
        int sumOfNodes = left.second + right.second + root->val;
        
        if(root->val == (sumOfNodes/countOfNodes)){
            cnt++;
        }
        
        return {countOfNodes,sumOfNodes};
        
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        recur(root,cnt);
        return cnt;
    }
};