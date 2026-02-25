class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        long long maxWidth = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()){
            int size = q.size();
            long long firstIndex = q.front().second;
            long long first = 0, last = 0;

            for(int i = 0; i < size; i++){
                auto frontNode = q.front();
                q.pop();

                TreeNode* node = frontNode.first;
                long long index = frontNode.second - firstIndex; // normalize

                if(i == 0) first = index;
                if(i == size - 1) last = index;

                if(node->left){
                    q.push({node->left, 2 * index});
                }

                if(node->right){
                    q.push({node->right, 2 * index + 1});
                }
            }

            maxWidth = max(maxWidth, last - first + 1);
        }

        return (int)maxWidth;
    }
};
