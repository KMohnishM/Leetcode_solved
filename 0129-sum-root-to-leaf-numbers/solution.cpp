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
    void traverse(TreeNode* node, int current, int &total) {
        if(node == NULL) return;

        current = current * 10 + node->val;

        
        if(node->left == NULL && node->right == NULL) {
            total += current;
            return;
        }

        traverse(node->left, current, total);
        traverse(node->right, current, total);
    }

    int sumNumbers(TreeNode* root) {
        int total=0;
        traverse(root,0,total);
        return total;
    }
};
