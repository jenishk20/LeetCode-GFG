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
    int idx=0;
    TreeNode *recur(vector<int>&preorder,vector<int>&inorder,unordered_map<int,int>&ma,int st,int en)
    {
        if(st>en)
            return NULL;
       
        int curr=preorder[idx++];
        TreeNode *newNode=new TreeNode(curr);
        if(st==en)
            return newNode;
        int mid=ma[curr];
        newNode->left=recur(preorder,inorder,ma,st,mid-1);
        newNode->right=recur(preorder,inorder,ma,mid+1,en);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>ma;
        int n=inorder.size();
        for(int i=0;i<n;i++)
        {
            ma[inorder[i]]=i;
        }
        return recur(preorder,inorder,ma,0,n-1);
    }
};