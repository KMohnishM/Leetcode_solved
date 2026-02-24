class Solution {
public:
    void traverse(TreeNode* node, int current, int &total) {
        if(node == NULL) return;

        current = current * 2 + node->val;

        
        if(node->left == NULL && node->right == NULL) {
            total += current;
            return;
        }

        traverse(node->left, current, total);
        traverse(node->right, current, total);
    }

    int sumRootToLeaf(TreeNode* root) {
        int total = 0;
        traverse(root, 0, total);
        return total;
    }
};
