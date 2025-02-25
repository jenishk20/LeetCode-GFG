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
    int st = 0;
    TreeNode *recur(int left,int right,vector<int>&postorder,map<int,int>&dToI){
        if(left>right) return NULL;
        
        int firstRoot = postorder[st--];
        int position = dToI[firstRoot];
        TreeNode *newNode = new TreeNode(firstRoot);
        newNode -> right = recur(position+1,right,postorder,dToI);
        newNode -> left = recur(left,position-1,postorder,dToI);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        map<int,int>dToI;
        for(int i=0;i<inorder.size();i++){
            dToI[inorder[i]] = i;
        }
        st = inorder.size()-1;
        return recur(0,inorder.size()-1,postorder,dToI);
    }
};