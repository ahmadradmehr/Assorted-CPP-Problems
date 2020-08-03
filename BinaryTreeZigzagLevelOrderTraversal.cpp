/* Binary Tree Zigzag Level Order Traversal
 * 
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *   3
 *  / \
 * 9  20
 *   /  \
 *  15   7
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
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
class ZigzagLevelOrder {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> res;
        unordered_map<TreeNode*, int> level;
        level[root] = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *t = q.front();
            q.pop();
            if (res.size() == level[t])
                res.push_back({t->val});
            else if (level[t] % 2 == 0)
                res.back().push_back(t->val);
            else if (level[t] % 2 == 1)
                res.back().insert(res.back().begin(), t->val);
            if (t->left) {
                q.push(t->left);
                level[t->left] = level[t] + 1;
            }
            if (t->right) {
                q.push(t->right);
                level[t->right] = level[t] + 1;
            }
        }
        return res;
    }
};