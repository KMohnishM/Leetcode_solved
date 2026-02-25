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
    int dfsheight(TreeNode* root){
        if(root==NULL)return 0;

        int a=dfsheight(root->left);
        if(a==-1)return -1;
        int b=dfsheight(root->right);
        if(b==-1)return -1;
        if(abs(b-a)>1)return -1;
        return max(a,b)+1;
    }
    bool isBalanced(TreeNode* root) {
        return dfsheight(root)!=-1;
    }

};
