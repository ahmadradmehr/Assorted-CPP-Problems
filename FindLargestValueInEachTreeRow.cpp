/*
 * ### Find Largest Value in Each Tree Row ###
 * 
 * 
 * Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
 * 
 * Example 1:
 * Input: root = [1,3,2,5,3,null,9]
 * Output: [1,3,9]
 * 
 * Example 2:
 * Input: root = [1,2,3]
 * Output: [1,3]
 * 
 * Example 3:
 * Input: root = [1]
 * Output: [1]
 * 
 * Example 4:
 * Input: root = [1,null,2]
 * Output: [1,2]
 * 
 * Example 5:
 * Input: root = []
 * Output: []
 * 
 * Constraints:
 * The number of nodes in the tree will be in the range [0, 104].
 * -231 <= Node.val <= 231 - 1
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
class LargestValueEachTreeRow {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return {};
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        vector<int> res;
        while (!q.empty()) {
            TreeNode *t = q.front().first;
            int level = q.front().second;
            q.pop();
            if (res.size() <= level)
                res.push_back(t->val);
            else if (res[level] < t->val)
                res[level] = t->val;
            if (t->left)
                q.push({t->left, level+1});
            if (t->right)
                q.push({t->right, level+1});
        }
        return res;
    }
};