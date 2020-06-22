/* Balanced Binary Tree
 * 
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as:
 * a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
 * 
 * Example 1:
 * Given the following tree [3,9,20,null,null,15,7]:
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 * Return true.
 * 
 * Example 2:
 * Given the following tree [1,2,2,3,3,null,null,4,4]:
 *       1
 *      / \
 *     2   2
 *    / \
 *   3   3
 *  / \
 * 4   4
 * Return false.
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

class BalancedBinaryTree {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (abs(treeDepth(t->right) - treeDepth(t->left)) > 1)
                return false;
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        return true;
    }
    
    int treeDepth(TreeNode* root) {
        if (!root)
            return 0;
        return max(treeDepth(root->right), treeDepth(root->left)) + 1;
    }
};