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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int>ans;
        
        if(!root) return ans;
        
        stack<TreeNode *>s1;
       
        
        while(root or !s1.empty()){
            
            if(root){
                s1.push(root);
                root = root -> left;
            }
            else{
                
                auto curr = s1.top()->right;
                if(curr == NULL){
                    
                    curr = s1.top();
                    s1.pop();    
                    ans.push_back(curr->val);
        
                    while(!s1.empty() and s1.top()->right == curr){
                        curr = s1.top();
                        cout<<curr->val<<endl;
                        ans.push_back(curr->val);
                        s1.pop();
                    }
                }
                else{
                    root = curr;
                }
            }
            
        }
        
        return ans;
    }
};