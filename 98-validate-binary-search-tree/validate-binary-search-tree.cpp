class Solution {
public:

    bool validate(TreeNode* root, long long minVal, long long maxVal) {

        // Empty tree is valid
        if (root == nullptr)
            return true;

        // Current node must be inside the allowed range
        if (root->val <= minVal || root->val >= maxVal)
            return false;

        // Left subtree must be smaller
        // Right subtree must be larger
        return validate(root->left, minVal, root->val) &&
               validate(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};