/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        queue<TreeNode *>q;
        string temp = "";
        
        if(!root) return temp;
        
        q.push(root);
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            if(curr == NULL){
                temp += "#,";
                continue;
            }
            
            temp += to_string(curr->val) + ",";
            
            q.push(curr->left);
         
            q.push(curr->right);
           
        }
        
        cout<<temp<<endl;
        return temp;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size() == 0) return NULL;
        
       
        queue<TreeNode *>q;
        
        string str = "";
        stringstream s(data);
        getline(s,str,',');
        
        TreeNode *root = new TreeNode(stoi(str));
        
        q.push(root);
        
        while(!q.empty()){
            
            auto curr = q.front();
            q.pop();
            
            getline(s,str,',');
            
            if(str == "#") curr->left = NULL;
            else{
                TreeNode *leftNode = new TreeNode(stoi(str));
                curr->left = leftNode;
                q.push(leftNode);
            }
            
            getline(s,str,',');
            
            if(str == "#") curr->right = NULL;
            else{
                TreeNode *rightNode = new TreeNode(stoi(str));
                curr->right = rightNode;
                q.push(rightNode);
            }
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));