/* Binary Tree Right Side View
 * 
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 * 
 * Example:
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 *    1            <---
 *  /   \
 * 2     3         <---
 *  \     \
 *   5     4       <---
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
class RightSideView {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        vector<int> res;
        queue<TreeNode*> q;
        unordered_map<TreeNode*, int> level;
        q.push(root);
        level[root] = 1;
        while (!q.empty()) {
            TreeNode *t = q.front();
            q.pop();
            if (level[t] > res.size()) {
                res.push_back(t->val);
            } else {
                res.at(level[t]-1) = t->val;
            }
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