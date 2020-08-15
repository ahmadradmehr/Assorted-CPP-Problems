/* Validate Binary Search Tree
 * 
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * Assume a BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * Example 1:
 *   2
 *  / \
 * 1   3
 * Input: [2,1,3]
 * Output: true
 * 
 * Example 2:
 *   5
 *  / \
 * 1   4
 *    / \
 *   3   6
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
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

class ValidBST {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, NULL, NULL);
    }
    
    bool isValid(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {
        if (!root)
            return true;
        if (minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;
        return isValid(root->left, minNode, root) && isValid(root->right, root, maxNode);
    }
};

// class ValidBST {
// public:
//     bool isValidBST(TreeNode* root) {
//         if (!root)
//             return true;
//         vector<int> nodes {root->val};
//         createVector(root, nodes, 0);
//         for (int i {1}; i < nodes.size(); i++) {
//             if (nodes.at(i) <= nodes.at(i-1))
//                 return false;
//         }
//         return true;
//     }
    
//     void createVector(TreeNode* root, vector<int> &nodes, int ind) {
//         if (root->right) {
//             nodes.insert(nodes.begin()+ind+1, root->right->val);
//             createVector(root->right, nodes, ind+1);
//         }
//         if (root->left) {
//             nodes.insert(nodes.begin()+ind, root->left->val);
//             createVector(root->left, nodes, ind);
//         }
//     }
// };