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
    map<TreeNode *, pair<int,int>>ma;
    void dfs(TreeNode *root, int hLevel, int vLevel){
        if(!root) return;

        ma[root] = {hLevel,vLevel};
        dfs(root->left,hLevel-1,vLevel-1);
        dfs(root->right,hLevel+1,vLevel-1);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>>ans;
        dfs(root,0,0);

        map<int,vector<int>>yMap;
        
        for(auto it : ma){
            yMap[it.second.first].push_back(it.first->val);
        }

        for(auto it : yMap) ans.push_back(it.second);

        return ans;
    }
};