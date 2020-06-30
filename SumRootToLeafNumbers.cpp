/* Sum Root to Leaf Numbers
 * 
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 * Find the total sum of all root-to-leaf numbers.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * Input: [1,2,3]
 *   1
 *  / \
 * 2   3
 * Output: 25
 * Explanation:
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Therefore, sum = 12 + 13 = 25.
 * 
 * Example 2:
 * Input: [4,9,0,5,1]
 *     4
 *    / \
 *   9   0
 *  / \
 * 5   1
 * Output: 1026
 * Explanation:
 * The root-to-leaf path 4->9->5 represents the number 495.
 * The root-to-leaf path 4->9->1 represents the number 491.
 * The root-to-leaf path 4->0 represents the number 40.
 * Therefore, sum = 495 + 491 + 40 = 1026.
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
 
class SumNumbers {
public:
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        int sum = 0;
        stack<TreeNode*> st;
        st.push(root);
        unordered_map<TreeNode*, int> vals;
        vals[root] = root->val;
        while (!st.empty()) {
            TreeNode* t = st.top();
            st.pop();
            if (!t->right && !t->left) {
                sum += vals[t];
            } else if (!t->right) {
                vals[t->left] = vals[t] * 10 + t->left->val;
                st.push(t->left);
            } else if (!t->left) {
                vals[t->right] = vals[t] * 10 + t->right->val;
                st.push(t->right);
            } else {
                vals[t->left] = vals[t] * 10 + t->left->val;
                st.push(t->left);
                vals[t->right] = vals[t] * 10 + t->right->val;
                st.push(t->right);
            }
        }
        return sum;
    }
};