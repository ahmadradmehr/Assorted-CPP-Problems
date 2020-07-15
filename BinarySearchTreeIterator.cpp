/* Binary Search Tree Iterator
 * 
 * Implement an iterator over a binary search tree (BST).
 * Your iterator will be initialized with the root node of a BST.
 * Calling next() will return the next smallest number in the BST.
 * 
 * Example:
 *     7
 *    / \
 *   3  15
 *      / \
 *     9   20
 * 
 * BSTIterator iterator = new BSTIterator(root);
 * iterator.next();    // return 3
 * iterator.next();    // return 7
 * iterator.hasNext(); // return true
 * iterator.next();    // return 9
 * iterator.hasNext(); // return true
 * iterator.next();    // return 15
 * iterator.hasNext(); // return true
 * iterator.next();    // return 20
 * iterator.hasNext(); // return false
 * 
 * Note:
 * next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 * You may assume that next() call will always be valid, that is, there will be at least a next smallest number in the BST when next() is called.
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

class BSTIterator {
    stack<TreeNode*> st;
    void pushNodes(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushNodes(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *min_node = st.top();
        st.pop();
        pushNodes(min_node->right);
        return min_node->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// **Initial Solution**

// class BSTIterator {
//     TreeNode *min_node, *current;
//     unordered_map<TreeNode*, TreeNode*> parent;
    
// public:
//     BSTIterator(TreeNode* root) : min_node {root}, current {NULL} {
//         parent[min_node] = NULL;
//         while (min_node && min_node->left) {
//             parent[min_node->left] = min_node;
//             min_node = min_node->left;
//         }
//     }
    
//     /** @return the next smallest number */
//     int next() {
//         hasNext();
//         current = min_node;
//         return min_node->val;
//     }
    
//     /** @return whether we have a next smallest number */
//     bool hasNext() {
//         if (!current && !min_node)
//             return false;
//         if (current != min_node)
//             return true;
//         while (true) {
//             if (min_node->left && !parent.count(min_node->left)) {
//                 while (min_node->left) {
//                     parent[min_node->left] = min_node;
//                     min_node = min_node->left;
//                 }
//                 break;
//             } else if (current != min_node) {
//                 break;
//             } else if (min_node->right && !parent.count(min_node->right)) {
//                 parent[min_node->right] = min_node;
//                 min_node = min_node->right;
//             } else {
//                 while (parent[min_node] && parent[min_node]->right == min_node)
//                     min_node = parent[min_node];
//                 if (parent[min_node] && parent[min_node]->left == min_node) {
//                     min_node = parent[min_node];
//                     break;
//                 } else
//                     return false;
//             }
//         }
//         return true;
//     }
// };