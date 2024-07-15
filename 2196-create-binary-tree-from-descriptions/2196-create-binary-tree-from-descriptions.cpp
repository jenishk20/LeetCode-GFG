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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
              TreeNode *curr;
        map<int,TreeNode *>ma;
        map<int,int>ma1;

        for(auto &it : descriptions){
            ma1[it[1]] = it[0];
            if(ma.find(it[0]) == ma.end()){
                curr = new TreeNode(it[0]);
                ma[it[0]] = curr;
                
                if(ma.find(it[1])!=ma.end()){
                    if(it[2])
                        curr->left = ma[it[1]];
                    else
                        curr->right = ma[it[1]];
                }
                else{
                    if(it[2]){
                        curr->left = new TreeNode(it[1]);
                        ma[it[1]] = curr->left;
                    }
                    else{
                        curr->right = new TreeNode(it[1]);
                        ma[it[1]] = curr->right;
                    }
                }
            }
            else{
                curr = ma[it[0]];
                if(ma.find(it[1])!=ma.end()){
                    if(it[2])
                        curr->left = ma[it[1]];
                    else
                        curr->right = ma[it[1]];
                }
                else{
                    if(it[2]){
                        curr->left = new TreeNode(it[1]);
                        ma[it[1]] = curr->left;
                    }
                    else{
                        curr->right = new TreeNode(it[1]);
                        ma[it[1]] = curr->right;
                    }
                }
            }
        }

        for(auto &it : descriptions){
            if(ma1.find(it[0]) == ma1.end()){
                return ma[it[0]];
            }
        }
        return NULL;
    }
};