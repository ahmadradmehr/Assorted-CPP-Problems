/* Kth Smallest Element in a BST
 * 
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 * 
 * Example 1:
 * Input: root = [3,1,4,null,2], k = 1
 *   3
 *  / \
 * 1   4
 *  \
 *   2
 * Output: 1
 * 
 * Example 2:
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 *        5
 *       / \
 *      3   6
 *     / \
 *    2   4
 *   /
 *  1
 * Output: 3
 * 
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? 
 * How would you optimize the kthSmallest routine?
 * 
 * Constraints:
 * The number of elements of the BST is between 1 to 10^4.
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
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
class KthSmallestBST {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        st.push(root);
        TreeNode *t = st.top();
        while (t->left) {
            t = t->left;
            st.push(t);
        }
        while (true) {
            t = st.top();
            st.pop();
            k--;
            if (k == 0)
                break;
            if (t->right) {
                t = t->right;
                st.push(t);
                while (t->left) {
                    t = t->left;
                    st.push(t);
                }
            }
        }
        return t->val;
    }
};