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
    int maxsum(TreeNode* root,int &ans){
        if(root==NULL)return 0;
        int l=0,r=0;
        if(root->left)l=max(0,maxsum(root->left,ans));
        if(root->right)r=max(0,maxsum(root->right,ans));
        ans=max(ans,l+r+root->val);
        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        int ans=-10000;
        maxsum(root,ans);
        return ans;
    }
};
