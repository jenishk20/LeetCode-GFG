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
    int cnt = 0;
    vector<int>dfs(TreeNode *root,int &distance){
        if(!root) return {};

        if(!root->left and !root->right) return {1};

        vector<int>lArr = dfs(root->left,distance);
        vector<int>rArr = dfs(root->right,distance);

        vector<int>mergedArr;
      
        for(int i=0;i<lArr.size();i++){
            for(int j=0;j<rArr.size();j++){
                int dist = lArr[i] + rArr[j];
                if(dist<=distance){
                    cnt++;
                }
            }
        }
        for(auto it : lArr){
            mergedArr.push_back(it+1);
        }
        for(auto it : rArr){
            mergedArr.push_back(it+1);
        }
        
        return mergedArr;

    }
    int countPairs(TreeNode* root, int distance) {
          
        dfs(root,distance);
        return cnt;
    }
};