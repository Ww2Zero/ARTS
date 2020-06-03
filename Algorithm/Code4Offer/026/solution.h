// https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (B == NULL) {
            return false;
        }
        if (A == NULL && B != NULL) {
            return false;
        }

        if (A->val == B->val) {
            if (dfs(A, B)) {
                return true;
            }
        }
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool dfs(TreeNode *A, TreeNode *B) {
        if (B == NULL) {
            return true;
        }
        if (A == NULL && B != NULL) {
            return false;
        }
        if (A->val == B->val) {
            if (dfs(A->left, B->left) && dfs(A->right, B->right)) {
                return true;
            } else {
                return false;
            }

        } else {
            return false;
        }
    }
};