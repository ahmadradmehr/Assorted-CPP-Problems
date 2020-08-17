/* Binary Tree Paths
 * 
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * Input:
 *    1
 *  /   \
 * 2     3
 *  \
 *   5
 * Output: ["1->2->5", "1->3"]
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
class BinaryTreePaths {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root)
            return {};
        vector<string> res;
        Path(root, res, to_string(root->val));
        return res;
    }
    
    void Path(TreeNode* root, vector<string> &res, string current) {
        if (!root->left && !root->right)
            res.push_back(current);
        if (root->left)
            Path(root->left, res, current + "->" + to_string(root->left->val));
        if (root->right)
            Path(root->right, res, current + "->" + to_string(root->right->val));
    }
};