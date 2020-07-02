/* Binary Tree Level Order Traversal II
 * 
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values.
 * (ie, from left to right, level by level from leaf to root).
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 * return its bottom-up level order traversal as:
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
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
//class LevelOrderBottom {
//public:
//    vector<vector<int>> levelOrderBottom(TreeNode* root) {
//        if (!root) return vector<vector<int>>();
//        vector<vector<int>> vv;
//        vector<int> v;
//        int n {1}, current {0}, next {0};
//        v.push_back(root->val);
//        vv.push_back(v);
//        v.clear();
//        std::queue<TreeNode*> q;
//        q.push(root->left);
//        q.push(root->right);
//        if (root->left && root->right)
//            current = 2;
//        else if ((root->left && !root->right) || (!root->left && root->right))
//            current = 1;
//        while (!q.empty()) {
//            TreeNode* p = q.front();
//            q.pop();
//            if (!p) continue;
//            v.push_back(p->val);
//            q.push(p->left);
//            q.push(p->right);
//            current--;
//            if (p->left && p->right)
//                next += 2;
//            else if ((p->left && !p->right) || (!p->left && p->right))
//                next++;
//            if (current == 0) {
//                vv.insert(vv.begin(), v);
//                v.clear();
//                current = next;
//                next = 0;
//                n++;
//            }
//        }
//        return vv;
//    }
//};

class LevelOrderBotto {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        unordered_map<TreeNode*, int> level;
        level[root] = 0;
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (level[t] == res.size())
                res.insert(res.begin(), {t->val});
            else
                res.front().push_back(t->val);
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