/* Sum of Left Leaves
 * 
 * Find the sum of all left leaves in a given binary tree.
 * Example:
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 * There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
 */

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
class SumOfLeftLeaves {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;
        int sum {0};
        queue<pair<TreeNode*, bool>> q;
        q.push({root, false});
        while (!q.empty()) {
            pair<TreeNode*, bool> t = q.front();
            q.pop();
            if (!t.first->left && !t.first->right && t.second)
                sum += t.first->val;
            if (t.first->left)
                q.push({t.first->left, true});
            if (t.first->right)
                q.push({t.first->right, false});
        }
        return sum;
    }
};