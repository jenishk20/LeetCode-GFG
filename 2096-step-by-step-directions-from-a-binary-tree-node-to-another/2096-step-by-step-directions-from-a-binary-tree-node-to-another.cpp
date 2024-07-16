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
private:
    vector<string>ans;
public:
    void dfs(TreeNode *root,int startValue,string &path){
        if(!root) return;   
        
        if(root->val == startValue){
            ans.push_back(path);
            return;
        }
        if(root->left){
            path += 'L';
            dfs(root->left,startValue,path);
            path.pop_back();
        }

        if(root->right){
            path += 'R';
            dfs(root->right,startValue,path);
            path.pop_back();     
        }
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path = "";
        dfs(root,startValue,path);
        path = "";
        dfs(root,destValue,path);

        string first = ans[0];
        string second = ans[1];

        int n = first.size();
        int m = second.size();
        int i=0,j=0;

        while(i<n and j<m){
            if(first[i]!=second[j]) break;
            i++;
            j++;
        }

        for(int k=i;k<n;k++){
            first[k] = 'U';
        }
        
        string res = first.substr(i) + second.substr(j);
        return res;
    }
};