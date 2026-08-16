class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int answer = 0;

        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (node == nullptr || count >= k)
                return;

            inorder(node->left);

            count++;

            if (count == k) {
                answer = node->val;
                return;
            }

            inorder(node->right);
        };

        inorder(root);

        return answer;
    }
};