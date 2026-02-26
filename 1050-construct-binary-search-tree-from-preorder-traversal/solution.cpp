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
    TreeNode* insert(TreeNode* root,int val){
        
        if(root->val>val){
            if(root->left){
              insert(root->left,val);
            }
            else{
                TreeNode* tmp=new TreeNode(val);
                root->left=tmp;
            }
        }
        if(root->val<val){
            if(root->right){
              insert(root->right,val);
            }
            else{
                TreeNode* tmp=new TreeNode(val);
                root->right=tmp;
            }
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* head=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            insert(head,preorder[i]);
        }
        return head;
    }
};
