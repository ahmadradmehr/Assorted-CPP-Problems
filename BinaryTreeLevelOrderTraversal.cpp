/* Binary Tree Level Order Traversal
 * 
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
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
class LevelOrder {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        unordered_map<TreeNode*, int> parents;
        q.push(root);
        parents[root] = 0;
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (res.size() <= parents[t])
                res.emplace_back(vector<int> {t->val});
            else
                res.at(parents[t]).push_back(t->val);
            if (t->left) {
                q.push(t->left);
                parents[t->left] = parents[t] + 1;
            }
            if (t->right) {
                q.push(t->right);
                parents[t->right] = parents[t] + 1;
            }
        }
        return res;
    }
};