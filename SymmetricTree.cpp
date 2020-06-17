/* Symmetric Tree
 * 
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 *    1
 *   / \
 *  2   2
 *   \   \
 *    3   3
 * 
 * Follow up: Solve it both recursively and iteratively.
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
// class SymmetricTree {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (!root)
//             return true;
//         return helper(root->right, root->left);
//     }
//     bool helper(TreeNode *r, TreeNode *l) {
//         if (!r && !l)
//             return true;
//         if (!r || !l)
//             return false;
//         return (r->val == l->val) && helper(r->right, l->left) && helper (r->left, l->right);
//     }
// };

// class SymmetricTree {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (!root) return true;
//         std::queue<std::pair<TreeNode*, TreeNode*>> q;
//         q.push(std::make_pair(root->right, root->left));
//         while (!q.empty()) {
//             std::pair<TreeNode*, TreeNode*> p = q.front();
//             q.pop();
//             if (!p.first && !p.second) continue;
//             if ((!p.first && p.second) || (p.first && !p.second)) return false;
//             if (p.first->val != p.second->val) return false;
//             q.push(make_pair(p.first->right, p.second->left));
//             q.push(make_pair(p.first->left, p.second->right));
//         }
//         return true;
//     }
// };

class SymmetricTree {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        std::stack<std::pair<TreeNode*, TreeNode*>> s;
        s.push(make_pair(root->left, root->right));
        while (!s.empty()) {
            std::pair<TreeNode*, TreeNode*> p = s.top();
            s.pop();
            if ((!p.first && p.second) || (p.first && !p.second)) return false;
            if (!p.first && !p.second) continue;
            if (p.first->val != p.second->val) return false;
            s.push(make_pair(p.first->left, p.second->right));
            s.push(make_pair(p.first->right, p.second->left));
        }
        return true;
    }
};