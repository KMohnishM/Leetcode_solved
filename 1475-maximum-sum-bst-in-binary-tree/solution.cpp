class Solution {
public:
    int maxSum = 0;
    
    struct Info {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };
    
    Info dfs(TreeNode* root) {
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN};
        }
        
        Info left = dfs(root->left);
        Info right = dfs(root->right);
        
        Info curr;
        
        if (left.isBST && right.isBST &&
            left.maxVal < root->val &&
            root->val < right.minVal) {
            
            curr.isBST = true;
            curr.sum = left.sum + right.sum + root->val;
            curr.minVal = min(root->val, left.minVal);
            curr.maxVal = max(root->val, right.maxVal);
            
            maxSum = max(maxSum, curr.sum);
        }
        else {
            curr.isBST = false;
        }
        
        return curr;
    }
    
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
