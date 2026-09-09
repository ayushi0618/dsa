class Solution {
public:
    bool check(TreeNode* root, long long low, long long high) {
        if (!root) return true;

        if (root->val <= low || root->val >= high)
            return false;

        return check(root->left, low, root->val) &&
               check(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};
