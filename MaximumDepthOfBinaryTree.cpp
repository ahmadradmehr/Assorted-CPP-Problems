/* Maximum Depth of Binary Tree
 * 
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *  /  \
 * 15   7
 * return its depth = 3.
 */
 
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class MaxDepth {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int n {1}, current {0}, next {0};
        std::queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        if (root->left && root->right)
            current = 2;
        else if ((!root->right && root->left) ||(root->right && !root->left))
            current = 1;
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (!t) continue;
            current--;
            q.push(t->right);
            q.push(t->left);
            if (t->right && t->left)
                next += 2;
            else if ((!t->right && t->left) || (t->right && !t->left))
                next++;
            if (current == 0) {
                current = next;
                next = 0;
                n++;
            }
        }
        return n;
    }
};