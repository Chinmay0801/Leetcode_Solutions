class Solution {
public:

    // Checks if two trees are exactly the same
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == nullptr && q == nullptr)
            return true;

        if (p == nullptr || q == nullptr)
            return false;

        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // Empty subtree is always a subtree
        if (subRoot == nullptr)
            return true;

        // Root is empty but subRoot isn't
        if (root == nullptr)
            return false;

        // Check if current tree matches subRoot
        if (isSameTree(root, subRoot))
            return true;

        // Search in left or right subtree
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};