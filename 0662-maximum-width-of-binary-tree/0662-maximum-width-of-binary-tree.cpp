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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode *,int>>q;
        q.push({root,0});
        int i,ans=0;
        while(!q.empty())
        {
            int sz=q.size();
            int first,last;
            int min=q.front().second; // Check Overflow Condition
            for(i=0;i<sz;i++)
            {
                TreeNode *curr=q.front().first;
               int curr_idx=q.front().second-min;
                
                q.pop();
                
                  if(i==0)
                    first=curr_idx;
                if(i==sz-1)
                    last=curr_idx;
                if(curr->left)
                    q.push({curr->left,2*curr_idx+1});
                if(curr->right)
                    q.push({curr->right,2*curr_idx+2});
                
              
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};