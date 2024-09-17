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
    int idx = 0;
    TreeNode *recur(int low,int high,vector<int>&inorder,
                   vector<int>&postorder,map<int,int>&ma){
        
        if(low>high) return NULL;
        
        int node = postorder[idx--];
        TreeNode *newNode = new TreeNode(node);
        
        if(low == high) return newNode;
        
        int mid = ma[node];
        newNode->right = recur(mid+1,high,inorder,postorder,ma);
        newNode->left = recur(low,mid-1,inorder,postorder,ma);
        
        
        return newNode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>ma;
        
        int n = inorder.size();
        idx = n-1;
        for(int i=0;i<n;i++){
            ma[inorder[i]] = i;    
        }
        
        return recur(0,n-1,inorder,postorder,ma);
    }
};