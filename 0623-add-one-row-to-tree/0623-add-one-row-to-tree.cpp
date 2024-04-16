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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        queue<TreeNode *>q;
        q.push(root);
        
        
        if(depth==1)
        {
            TreeNode *temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        int currDepth=2;
        bool be=false;
        
        while(!q.empty())
        {
            int sz=q.size();
            
            if(currDepth==depth)
            {
                be=true;
            }
            for(int i=0;i<sz;i++)
            {
                TreeNode *node=q.front();
                q.pop();
                if(be)
                {
                    
                    TreeNode *temp=node->left;
                    TreeNode *temp1=node->right;
                    node->left=new TreeNode(val);
                    node->right=new TreeNode(val);
                    
                    node->left->right=NULL;
                    node->right->left=NULL;
                    node->left->left=temp;
                    node->right->right=temp1;
                    break;
                    
                }
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            currDepth++;
        }
        return root;
        
    }
};