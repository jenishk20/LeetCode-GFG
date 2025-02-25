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

TreeNode *recur(int preSt,int preEnd,int postSt,vector<int>&preorder,vector<int>&postorder,map<int,int>&postToI){
    if(preSt > preEnd) return NULL;
    if(preSt == preEnd) return new TreeNode(preorder[preSt]);
   
    TreeNode *newNode = new TreeNode(preorder[preSt]);
    int nextNode = preorder[preSt+1];
    int idxInPost = postToI[nextNode];
    int eles = idxInPost - postSt + 1;

    newNode -> left = recur(preSt+1, preSt + eles,postSt,preorder,postorder,postToI);
    newNode -> right = recur(preSt + eles + 1, preEnd, idxInPost+1,preorder,postorder,postToI);

    return newNode;
}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        map<int,int>postToI;
        int n = postorder.size();

        for(int i=0;i<n;i++){
            postToI[postorder[i]] = i;
        }
        return recur(0,n-1,0,preorder,postorder,postToI);
    }
};