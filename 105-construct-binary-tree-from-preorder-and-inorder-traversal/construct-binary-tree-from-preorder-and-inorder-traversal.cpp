class Solution {
public:

    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store index of every value in inorder
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int left, int right) {

        // No elements left
        if (left > right)
            return nullptr;

        // First element of preorder is the root
        int rootValue = preorder[preIndex];
        preIndex++;

        TreeNode* root = new TreeNode(rootValue);

        // Find root position in inorder
        int inorderIndex = mp[rootValue];

        // Build left subtree
        root->left = build(preorder, left, inorderIndex - 1);

        // Build right subtree
        root->right = build(preorder, inorderIndex + 1, right);

        return root;
    }
};