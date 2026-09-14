/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
 * };
 */

class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        cnt = 0;
        dfs(root);
        return cnt;
    }

private:
    int cnt;

    // returns pair {sum, count}
    pair<long long,int> dfs(TreeNode* node) {
        if (!node) return {0LL, 0};
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        long long sum = left.first + right.first + node->val;
        int c = left.second + right.second + 1;
        long long avg = sum / c; // integer division rounds down
        if (avg == node->val) ++cnt;
        return {sum, c};
    }
};
