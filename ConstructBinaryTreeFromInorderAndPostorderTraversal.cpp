/* Construct Binary Tree from Inorder and Postorder Traversal
 * 
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * Return the following binary tree:
 *   3
 *  / \
 * 9  20
 *   /  \
 *  15   7
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
class BuildTree {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return create(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    
    TreeNode* create(vector<int> &inorder, vector<int> &postorder, int il, int ir, int pl, int pr) {
        if (pl > pr)
            return NULL;
        TreeNode* t = new TreeNode(postorder.at(pr));
        int ipos {0};
        for (int i {il}; i <= ir; i++) {
            if (inorder.at(i) == postorder.at(pr)) {
                ipos = i;
                break;
            }
        }
        t->left = create(inorder, postorder, il, ipos-1, pl, pl + ipos - il - 1);
        t->right = create(inorder, postorder, ipos+1, ir, pl + ipos -il, pr - 1);
        return t;
    }
};