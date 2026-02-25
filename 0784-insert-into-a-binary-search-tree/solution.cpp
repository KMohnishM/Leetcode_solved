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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* tmp=new TreeNode(val);
            return tmp;
        }
        if(root->val>val){
            if(root->left){
              insertIntoBST(root->left,val);
            }
            else{
                TreeNode* tmp=new TreeNode(val);
                root->left=tmp;
            }
            
        }
        else{
            if(root->right){
              insertIntoBST(root->right,val);
            }
            else{
                TreeNode* tmp=new TreeNode(val);
                root->right=tmp;
            }
            
        }
    return root;
    }
};
