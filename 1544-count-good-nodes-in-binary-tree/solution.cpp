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
    void count(TreeNode* root,int& ans,int max){
        if(root==NULL)return;
        if(root->val>=max){
            max=root->val;
            ans++;}
        if(root->left){
            count(root->left,ans,max);
        }
        if(root->right){
            count(root->right,ans,max);
        }
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        int max=0;
        count(root,ans,root->val);
        return ans;
    }
};
