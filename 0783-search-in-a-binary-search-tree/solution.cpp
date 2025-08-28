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
    // vector<int>arr;
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* n=new TreeNode();
        n=findnode(root,val);
    //    arr=printtree(n);
        return n;
    }
    TreeNode* findnode(TreeNode* root,int val){
        if(root==NULL){return NULL;}
        if(root->val==val){
            return root;
        }
        TreeNode* res=new TreeNode();
        TreeNode* res1=new TreeNode();
        res=findnode(root->left,val);
        if(res){return res;}
        res1=findnode(root->right,val);
        if(res1){return res1;}
         return NULL;
    }
    // vector<int> printtree(TreeNode* root){
    //     if(root==NULL){
    //         return arr;
    //     }
    //     arr.push_back(root->val);
    //     printtree(root->left);
    //     printtree(root->right);
    //     return arr;  
    // }
};
