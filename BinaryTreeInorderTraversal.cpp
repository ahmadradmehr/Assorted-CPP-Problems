/* Binary Tree Inorder Traversal
 * 
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * Input: [1,null,2,3]
 * 1
 *  \
 *   2
 *  /
 * 3
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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

// // Recursive Method

// class InorderTraversal {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         traverse(root, res);
//         return res;
//     }
    
//     void traverse(TreeNode* root, vector<int> &res) {
//         if (root == NULL)
//             return;
//         traverse(root->left, res);
//         res.push_back(root->val);
//         traverse(root->right, res);
//     }
// };

// Iterative Method
class InorderTraversal {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while (root != NULL || !st.empty()) {
            while (root != NULL) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};